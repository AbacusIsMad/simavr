#ifndef TEST_TOOLS_MAIN
#define TEST_TOOLS_MAIN

#include "shared.h"
#include "util.h"

//initialises an avr and a wrapper
py_avr_wrapper * py_sim_init(const char* fname, char* mmcu_name, bool do_startup);

void py_sim_reset(py_avr_wrapper * py, bool do_startup);
void py_sim_terminate(py_avr_wrapper * py);


#endif
