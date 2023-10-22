#ifndef TEST_TOOLS_UTIL
#define TEST_TOOLS_UTIL

#include "shared.h"

//returns the symbol pointed by label, or NULL if not found
avr_symbol_t * get_symbol(py_avr_wrapper * py, const char * label);
uint8_t * get_data_at_label(py_avr_wrapper * py, const char * label, uint32_t * size);
uint16_t get_sp(py_avr_wrapper * py);
avr_flashaddr_t get_ret_addr(py_avr_wrapper * py);
uint8_t * get_data_at_addr(py_avr_wrapper * py, uint16_t addr);

#endif
