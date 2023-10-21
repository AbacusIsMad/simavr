#ifndef TEST_TOOLS_MAIN
#define TEST_TOOLS_MAIN

#include "shared.h"

//initialises an avr and a wrapper
py_avr_wrapper * py_sim_init(const char* fname, char* mmcu_name, bool do_startup);

//returns the symbol pointed by label, or NULL if not found
avr_symbol_t * get_symbol(py_avr_wrapper * py, const char * label);

void py_sim_reset(py_avr_wrapper * py, bool do_startup);
void py_sim_terminate(py_avr_wrapper * py);

uint8_t * get_data_at_label(py_avr_wrapper * py, const char * label, uint32_t * size);



#endif
