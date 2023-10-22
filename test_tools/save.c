#include "save.h"

avr_save * py_avr_save(py_avr_wrapper * py, bool copy_flash){
	avr_save * momento = malloc(sizeof(avr_save));
	avr_t * avr = py->avr;
	momento->ioend = avr->ioend; momento->ramend = avr->ramend; momento->flashend = avr->flashend;
	//the values above will be used to allocate the appropriate section of memory
	momento->data = malloc((momento->ramend + 1) * sizeof(uint8_t));
	memcpy(momento->data, avr->data, momento->ramend + 1);
	//either copy memory or assign the same thing to it.
	momento->copy_flash = copy_flash;
	if (copy_flash){
		momento->flash = malloc((momento->flashend + 1) * sizeof(uint8_t));
		memcpy(momento->flash, avr->flash, (momento->flashend + 1) * sizeof(uint8_t));
	} else momento->flash = avr->flash;
	
	//other copy by value attributes
	momento->cycle = avr->cycle;
	momento->run_cycle_count = avr->run_cycle_count;
	momento->run_cycle_limit = avr->run_cycle_limit;
	memcpy(momento->sreg, avr->sreg, sizeof(avr->sreg));
	momento->interrupt_state = avr->interrupt_state;
	momento->pc = avr->pc;
	momento->reset_pc = avr->reset_pc;
	
	return momento;
}

void py_avr_restore(py_avr_wrapper * py, avr_save * momento, bool copy_flash){

	avr_t * avr = py->avr;
	avr->ioend = momento->ioend; avr->ramend = momento->ramend; avr->flashend = momento->flashend;

	memcpy(avr->data, momento->data, momento->ramend + 1);
	//if the momento didn't copy the flash there is no point in copying (in fact undefined behaviour)
	if (copy_flash && momento->copy_flash){
		avr->flash = malloc((momento->flashend + 1) * sizeof(uint8_t));
		memcpy(avr->flash, momento->flash, (momento->flashend + 1) * sizeof(uint8_t));
	}
	
	avr->cycle = momento->cycle;
	avr->run_cycle_count = momento->run_cycle_count;
	avr->run_cycle_limit = momento->run_cycle_limit;
	memcpy(avr->sreg, momento->sreg, sizeof(momento->sreg));
	avr->interrupt_state = momento->interrupt_state;
	avr->pc = momento->pc;
	avr->reset_pc = momento->reset_pc;
}


void py_avr_free_save(avr_save * momento){
	if (momento == NULL) return;
	if (momento->copy_flash) free(momento->flash);
	free(momento->data);
	free(momento);
}
