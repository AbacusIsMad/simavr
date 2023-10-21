#ifndef TEST_TOOLS_SAVE
#define TEST_TOOLS_SAVE

#include "shared.h"

typedef struct avr_save {
	uint16_t			ioend;
	uint16_t 			ramend;
	uint32_t			flashend;
	
	avr_cycle_count_t	cycle;
	avr_cycle_count_t	run_cycle_count;
	avr_cycle_count_t	run_cycle_limit;
	uint8_t				sreg[8];
	
	int8_t				interrupt_state;
	
	avr_flashaddr_t		pc;
	avr_flashaddr_t		reset_pc;
	
	uint8_t *			flash;
	uint8_t *			data;
} avr_save;

avr_save * py_avr_save(py_avr_wrapper * py);

int py_avr_restore(py_avr_wrapper * py, avr_save * momento);

#endif
