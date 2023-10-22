#ifndef TEST_MAIN
#define TEST_MAIN

#include <avr/io.h>
#include <Arduino.h>
#include <stdio.h>
#include <stdint.h>

#ifndef cbi
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#endif
#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif
#ifndef sei
#define sei() __asm__ __volatile__ ("sei")
#endif
#ifndef cli
#define cli() __asm__ __volatile__ ("cli")
#endif

static FILE mystdout = {0};
static int uart_putchar(char c, FILE *stream)
{
	loop_until_bit_is_set(UCSR0A, UDRE0);
	UDR0 = c;
	return 0;
}

//copied from arduino cores
void sim_init()
{
	sei();
#if defined(TCCR0A) && defined(WGM01)
	sbi(TCCR0A, WGM01);
	sbi(TCCR0A, WGM00);
#endif
#if defined(__AVR_ATmega128__)
	sbi(TCCR0, CS02);
#elif defined(TCCR0) && defined(CS01) && defined(CS00)
	sbi(TCCR0, CS01);
	sbi(TCCR0, CS00);
#elif defined(TCCR0B) && defined(CS01) && defined(CS00)
	sbi(TCCR0B, CS01);
	sbi(TCCR0B, CS00);
#elif defined(TCCR0A) && defined(CS01) && defined(CS00)
	sbi(TCCR0A, CS01);
	sbi(TCCR0A, CS00);
#else
	#error Timer 0 prescale factor 64 not set correctly
#endif
#if defined(TIMSK) && defined(TOIE0)
	sbi(TIMSK, TOIE0);
#elif defined(TIMSK0) && defined(TOIE0)
	sbi(TIMSK0, TOIE0);
#else
	#error	Timer 0 overflow interrupt not set correctly
#endif
#if defined(TCCR1B) && defined(CS11) && defined(CS10)
	TCCR1B = 0;
	sbi(TCCR1B, CS11);
#if F_CPU >= 8000000L
	sbi(TCCR1B, CS10);
#endif
#elif defined(TCCR1) && defined(CS11) && defined(CS10)
	sbi(TCCR1, CS11);
#if F_CPU >= 8000000L
	sbi(TCCR1, CS10);
#endif
#endif
#if defined(TCCR1A) && defined(WGM10)
	sbi(TCCR1A, WGM10);
#endif
#if defined(TCCR2) && defined(CS22)
	sbi(TCCR2, CS22);
#elif defined(TCCR2B) && defined(CS22)
	sbi(TCCR2B, CS22);
#endif
#if defined(TCCR2) && defined(WGM20)
	sbi(TCCR2, WGM20);
#elif defined(TCCR2A) && defined(WGM20)
	sbi(TCCR2A, WGM20);
#endif
#if defined(TCCR3B) && defined(CS31) && defined(WGM30)
	sbi(TCCR3B, CS31);		// set timer 3 prescale factor to 64
	sbi(TCCR3B, CS30);
	sbi(TCCR3A, WGM30);		// put timer 3 in 8-bit phase correct pwm mode
#endif

#if defined(TCCR4A) && defined(TCCR4B) && defined(TCCR4D) /* beginning of timer4 block for 32U4 and similar */
	sbi(TCCR4B, CS42);		// set timer4 prescale factor to 64
	sbi(TCCR4B, CS41);
	sbi(TCCR4B, CS40);
	sbi(TCCR4D, WGM40);		// put timer 4 in phase- and frequency-correct PWM mode	
	sbi(TCCR4A, PWM4A);		// enable PWM mode for comparator OCR4A
	sbi(TCCR4C, PWM4D);		// enable PWM mode for comparator OCR4D
#else /* beginning of timer4 block for ATMEGA1280 and ATMEGA2560 */
#if defined(TCCR4B) && defined(CS41) && defined(WGM40)
	sbi(TCCR4B, CS41);		// set timer 4 prescale factor to 64
	sbi(TCCR4B, CS40);
	sbi(TCCR4A, WGM40);		// put timer 4 in 8-bit phase correct pwm mode
#endif
#endif /* end timer4 block for ATMEGA1280/2560 and similar */	
#if defined(TCCR5B) && defined(CS51) && defined(WGM50)
	sbi(TCCR5B, CS51);		// set timer 5 prescale factor to 64
	sbi(TCCR5B, CS50);
	sbi(TCCR5A, WGM50);		// put timer 5 in 8-bit phase correct pwm mode
#endif
#if defined(ADCSRA)
	// set a2d prescaler so we are inside the desired 50-200 KHz range.
	#if F_CPU >= 16000000 // 16 MHz / 128 = 125 KHz
		sbi(ADCSRA, ADPS2);
		sbi(ADCSRA, ADPS1);
		sbi(ADCSRA, ADPS0);
	#elif F_CPU >= 8000000 // 8 MHz / 64 = 125 KHz
		sbi(ADCSRA, ADPS2);
		sbi(ADCSRA, ADPS1);
		cbi(ADCSRA, ADPS0);
	#elif F_CPU >= 4000000 // 4 MHz / 32 = 125 KHz
		sbi(ADCSRA, ADPS2);
		cbi(ADCSRA, ADPS1);
		sbi(ADCSRA, ADPS0);
	#elif F_CPU >= 2000000 // 2 MHz / 16 = 125 KHz
		sbi(ADCSRA, ADPS2);
		cbi(ADCSRA, ADPS1);
		cbi(ADCSRA, ADPS0);
	#elif F_CPU >= 1000000 // 1 MHz / 8 = 125 KHz
		cbi(ADCSRA, ADPS2);
		sbi(ADCSRA, ADPS1);
		sbi(ADCSRA, ADPS0);
	#else // 128 kHz / 2 = 64 KHz -> This is the closest you can get, the prescaler is 2
		cbi(ADCSRA, ADPS2);
		cbi(ADCSRA, ADPS1);
		sbi(ADCSRA, ADPS0);
	#endif
	// enable a2d conversions
	sbi(ADCSRA, ADEN);
#endif

	// the bootloader connects pins 0 and 1 to the USART; disconnect them
	// here so they can be used as normal digital i/o; they will be
	// reconnected in Serial.begin()
#if defined(UCSRB)
	//UCSRB = 0;
#elif defined(UCSR0B)
	//UCSR0B = 0;
#endif
	fdev_setup_stream(&mystdout, uart_putchar, NULL, _FDEV_SETUP_WRITE);
  	stdout = &mystdout;
}

#ifdef __cplusplus
extern "C"
{
#endif
#include "result/include/simavr/avr/avr_mcu_section.h"
AVR_MCU(F_CPU, "atmega328p");
#ifdef __cplusplus
}
#endif

#endif
