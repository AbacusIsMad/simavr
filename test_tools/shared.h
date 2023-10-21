#ifndef TEST_TOOLS_SHARED
#define TEST_TOOLS_SHARED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <libgen.h>
#include <pthread.h>
#include <stdint.h>
#include <string.h>

#include "sim_avr.h"
#include "sim_core.h"
#include "avr_twi.h"
#include "sim_elf.h"
#include "sim_gdb.h"
#include "sim_vcd_file.h"

typedef struct py_avr_wrapper {
	avr_t * avr;
	uint32_t stop_addr;
	uint32_t symbolcount;
	avr_symbol_t ** symbol_addr_sorted;
	avr_symbol_t ** symbol_name_sorted;
} py_avr_wrapper;

#endif
