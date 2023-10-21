#ifndef TEST_TOOLS_FUNC
#define TEST_TOOLS_FUNC

#include "shared.h"

#include "save.h"
#include "util.h"

//the arg symbol name
#define ARG_BUFFER "arg_buffer"

avr_save * supervise_func_call(py_avr_wrapper * py, char * func_label, char * begin_label, uint8_t * arg_buf, uint8_t arg_len, int inst_limit);

int supervise_func_finalise(py_avr_wrapper * py, avr_save * momento, char * end_label);

int supervise_func_all(py_avr_wrapper * py, char * func, char * begin, char * end, uint8_t * arg_buf, uint8_t arg_len, int inst_limit, void (*validate)(py_avr_wrapper *));

int jump_to(py_avr_wrapper * py, avr_flashaddr_t pc);

int run_until(py_avr_wrapper * py, avr_flashaddr_t pc, uint32_t inst_limit);
#endif
