#ifndef TEST_TOOLS_FUNC
#define TEST_TOOLS_FUNC

#include "shared.h"

#include "save.h"
#include "util.h"

//the arg symbol name
#define ARG_BUFFER "arg_buffer"

/*
 * all functions in this test can be done equivialently in python
 * using the exposed API, but transferring data from ctypes to C is a bit more expensive.
 * this way it's also not needed to write so many custom functions.
 */

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

//this is the template for ctypes callback functions.
typedef int (*py_validate)(py_avr_wrapper *);


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
avr_save * supervise_func_call(
	py_avr_wrapper * py, //main object
	char * func_label, //function under test
	char * begin_label, //marks beginning of prologue
	uint8_t * arg_buf, //argument buffer
	uint8_t arg_len, //how much arguments (max 32 bytes for now)
	int inst_limit, //how long function is allowed to run
	py_validate prologue_validate, //prologue validation function
	py_validate running_validate //running validation function
);

//this returns the function to the starting point, before jumping to the end (ending it).
int supervise_func_finalise(
	py_avr_wrapper * py,
	avr_save * momento, //saved state from begin label
	char * end_label, //marks end of epilogue
	bool do_run, //try to run the epilogue instead of jumping
	py_validate epilogue_validate //the epilogue validation function, if applicable
);

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
);

int jump_to(py_avr_wrapper * py, avr_flashaddr_t pc);

int run_until(py_avr_wrapper * py, avr_flashaddr_t pc, uint32_t inst_limit, py_validate validate);
#endif
