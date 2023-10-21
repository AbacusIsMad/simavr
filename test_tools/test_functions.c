#include "test_functions.h"

/*
 * dealing with functions
 * you can't just call them in the c wrapper though. there's not enough control
 * for custom asm functions.
 * you have to:
 *		1: prepend with a label, so the simulator knows when to stop/restore
 *		2: make sure the function arguments come from ARG_BUFFER so simulation can modify values
 *		3: if a function returns something, [what do I do]
 *		4: append with a label so functions can be skipped
 */


/*
 * 1: find begin label, save state
 * 2: put arguments in according to ARG_BUFFER
 * 3: watch pc until it jumps to the desired function(label)
 *		3.1: save the return address pc (either stack or counting pc)
 * 4: watch pc until it returns
 * 		4.1: optional: check for whether it returns or not (HOW?)
 *			4.1.1: limit number of instructions
 * 5: evaluate results (responsibility of caller)
 * 6: reset to begin label, jump to end label
 */

avr_save * supervise_func_call(py_avr_wrapper * py, char * func_label, char * begin_label, uint8_t * arg_buf, uint8_t arg_len, int inst_limit){
	avr_symbol_t * begin = get_symbol(py, begin_label), * func = get_symbol(py, func_label),
	* sarg_buf = get_symbol(py, ARG_BUFFER);
	if (begin == NULL || func == NULL || sarg_buf == NULL) return NULL;
	//1
	jump_to(py, begin->addr);
	avr_save * momento = py_avr_save(py, false);
	
	//2
	memcpy(py->avr->data + (sarg_buf->addr - AVR_SEGMENT_OFFSET_DATA), arg_buf, arg_len > 32 ? 32 : arg_len);
	
	//3
	//using the stack method. Actually works for all types of calls.
	if (run_until(py, func->addr, 100) != 0) return NULL; //uh oh bad run
	avr_flashaddr_t ret = get_ret_addr(py);
	
	//4
	if (run_until(py, ret, inst_limit) != 0) return NULL; //took too long to get back
	
	return momento;
}

int supervise_func_finalise(py_avr_wrapper * py, avr_save * momento, char * end_label){
	if (momento != NULL){
		py_avr_restore(py, momento, false);
		py_avr_free_save(momento);
	}
	avr_symbol_t * end = get_symbol(py, end_label);
	if (end == NULL) return 1; //symbol not found
	
	jump_to(py, end->addr);
	return 0;
}

//this encapsulates the above, including having a ctypes callback function.
int supervise_func_all(py_avr_wrapper * py, char * func, char * begin, char * end, uint8_t * arg_buf, uint8_t arg_len, int inst_limit, void (*validate)(py_avr_wrapper *)){
	if (get_symbol(py, end) == NULL ||
		get_symbol(py, func) == NULL||
		get_symbol(py, begin) == NULL) {
		//always jump to the end, so that the next test actually works
		//on second thought maybe not
		//supervise_func_finalise(py, NULL, end);
		return 1;
	}
	avr_save * momento = NULL;
	//the call failed somehow
	if ((momento = supervise_func_call(py, func, begin, arg_buf, arg_len, inst_limit)) == NULL) {
		supervise_func_finalise(py, NULL, end);
		return 2;
	}
	
	//call ctypes func. This will handle result writing etc
	validate(py);
	
	supervise_func_finalise(py, momento, end);
	return 0;
}

//hopefully jumping is as easy as just setting the pc to be something else
int jump_to(py_avr_wrapper * py, avr_flashaddr_t pc){
	if (pc > py->avr->codeend) return 1; //invalid jump
	py->avr->pc = pc;
	return 0;
}

int run_until(py_avr_wrapper * py, avr_flashaddr_t pc, uint32_t inst_limit){
	uint32_t inst_count = 0;
	int state = 0;
	while(py->avr->pc != pc){
		state = avr_run(py->avr);
		if ((state == cpu_Done) || (state == cpu_Crashed)) return 1; //crashed
		inst_count++;
		if (inst_limit > 0 && inst_count > inst_limit) return 2; //reached limit
	}
	return 0;
}
