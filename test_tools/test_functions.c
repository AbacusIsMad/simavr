#include "test_functions.h"

avr_save * supervise_func_call(
	py_avr_wrapper * py, //main object
	char * func_label, //function under test
	char * begin_label, //marks beginning of prologue
	uint8_t * arg_buf, //argument buffer
	uint8_t arg_len, //how much arguments (max 32 bytes for now)
	int inst_limit, //how long function is allowed to run
	py_validate prologue_validate, //prologue validation function
	py_validate running_validate //running validation function
){
	avr_symbol_t * begin = get_symbol(py, begin_label), * func = get_symbol(py, func_label),
	* sarg_buf = get_symbol(py, ARG_BUFFER);
	if (begin == NULL || func == NULL || sarg_buf == NULL) return NULL;
	//1
	jump_to(py, begin->addr);
	//printf("addr 0x%08x, actual 0x%08x, waiting for 0x%08x\n", begin->addr, py->avr->pc, func->addr); 
	avr_save * momento = py_avr_save(py, false);
	
	//2
	memcpy(py->avr->data + (sarg_buf->addr - AVR_SEGMENT_OFFSET_DATA), arg_buf, arg_len > 32 ? 32 : arg_len);
	
	//3
	//using the stack method. Actually works for all types of calls.
	if (run_until(py, func->addr, 0, prologue_validate) != 0) { //uh oh bad run
		//don't forget to restore and clean up mess
		py_avr_restore(py, momento, false);
		py_avr_free_save(momento);
		return NULL;
	}
	avr_flashaddr_t ret = get_ret_addr(py);
	//printf("waiting for return address %x\n", ret);
	
	//4
	if (run_until(py, ret, inst_limit, running_validate) != 0) { //took too long to get back
		py_avr_restore(py, momento, false);
		py_avr_free_save(momento);
		return NULL; 
	}
	
	return momento;
}

//this returns the function to the starting point, before jumping to the end (ending it).
int supervise_func_finalise(
	py_avr_wrapper * py,
	avr_save * momento, //saved state from begin label
	char * end_label, //marks end of epilogue
	bool do_run, //try to run the epilogue instead of jumping
	py_validate epilogue_validate //the epilogue validation function, if applicable
){
	if (momento != NULL){
		if (!do_run) py_avr_restore(py, momento, false); //restore the context - something went wrong
	}
	avr_symbol_t * end = get_symbol(py, end_label);
	if (end == NULL) return 1; //symbol not found
	//even if epilogue_validate is NULL, still try to run it
	if (!do_run) jump_to(py, end->addr);
	else {
		if (run_until(py, end->addr, 0, epilogue_validate) != 0){
			//validation failed - restore context
			if (momento != NULL){
				py_avr_restore(py, momento, false);
			}
			jump_to(py, end->addr);
			if (momento != NULL){
				py_avr_free_save(momento);
			}
			return 1; //failed validation
		}
	}
	if (momento != NULL){
		py_avr_free_save(momento);
	}
	return 0;
}

//this encapsulates the above
//what's new: after_run_validate. This runs once.
int supervise_func_all(
	py_avr_wrapper * py,
	char * func,
	char * begin,
	char * end,
	uint8_t * arg_buf,
	uint8_t arg_len,
	int inst_limit,
	py_validate prologue_validate,
	py_validate running_validate,
	py_validate after_run_validate,
	py_validate epilogue_validate
){
	if (get_symbol(py, end) == NULL  ||
		get_symbol(py, func) == NULL ||
		get_symbol(py, begin) == NULL) {
		//always jump to the end, so that the next test actually works
		supervise_func_finalise(py, NULL, end, false, NULL);
		return 1;
	}
	avr_save * momento = NULL;
	//the call failed somehow
	if ((momento = supervise_func_call(py, func, begin, arg_buf,
			arg_len, inst_limit, prologue_validate, running_validate)) == NULL) {
		supervise_func_finalise(py, NULL, end, false, NULL);
		return 2;
	}
	
	//call ctypes func. This will handle result writing etc
	//if no validation function provided, succeed
	if (after_run_validate != NULL && after_run_validate(py) != 0){
		//puts("validation failed");
		supervise_func_finalise(py, momento, end, false, NULL);
	} else {
		//epilogue validation failed
		//puts("epilogue C");
		if (supervise_func_finalise(py, momento, end, true, epilogue_validate) != 0) return 3; 
	}
	return 0;
}

//hopefully jumping is as easy as just setting the pc to be something else
int jump_to(py_avr_wrapper * py, avr_flashaddr_t pc){
	if (pc > py->avr->codeend) return 1; //invalid jump
	py->avr->pc = pc;
	return 0;
}

int run_until(py_avr_wrapper * py, avr_flashaddr_t pc, uint32_t inst_limit, py_validate validate){
	uint32_t inst_count = 0;
	int state = 0;
	while(py->avr->pc != pc){
		//printf("pc at 0x%08x, target 0x%08x\n", py->avr->pc, pc);
		state = avr_run(py->avr);
		if ((state == cpu_Done) || (state == cpu_Crashed)) {
			return 1; //crashed
		}
		inst_count++;
		if (inst_limit > 0 && inst_count > inst_limit) {
			return 2; //reached limit
		}
		if (validate != NULL){
			if (validate(py) != 0){
				return 3; //validation failed
			}
		} else {
			//puts("no validation func");
		}
	}
	return 0;
}
