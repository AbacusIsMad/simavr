#include "main.h"
/*
=============
any variables used for setting up
=============
*/
uint8_t E2E_SWITCH = 0;	
//extern int a;
int a = 12;

uint8_t arg_buffer[32] = {0};
/*
==============
define your functions to test below
==============
*/
uint8_t woah(uint8_t a, uint8_t b){return 0;}

/*
==============
always remember to wrap your functions below
fname must be the same as what's called in the statement
==============
*/
#define BIND_AVR_LABELS "AVRBIND_"

#define UUT_WRAP_FUNC(fname, statement)\
	asm volatile(BIND_AVR_LABELS fname "_BEGIN:"); \
	{statement;} \
	asm volatile(BIND_AVR_LABELS fname "_END:");

void asm_function();

#include <stdint.h>
#include <stdio.h>
int main(){
	sim_init();
	int b = 0;
	if (E2E_SWITCH == 0){
		UUT_WRAP_FUNC("woah", a = woah(arg_buffer[0], arg_buffer[1]));
	} else { //E2E testing. This just gets run after function is validated
		//asm_function();
		b = printf("hello %d\n", b);
	}
	return 0;
}
