#ifndef _AVR_IO2323_H_
#define _AVR_IO2323_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "io2323.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define PINB _SFR_IO8(0x16)
#define DDRB _SFR_IO8(0x17)
#define PORTB _SFR_IO8(0x18)
#define EECR _SFR_IO8(0x1C)
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO8(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define WDTCR _SFR_IO8(0x21)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0 _SFR_IO8(0x33)
#define MCUSR _SFR_IO8(0x34)
#define MCUCR _SFR_IO8(0x35)
#define TIFR _SFR_IO8(0x38)
#define TIMSK _SFR_IO8(0x39)
#define GIFR _SFR_IO8(0x3A)
#define GIMSK _SFR_IO8(0x3B)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define TIMER0_OVF0_vect_num 2
#define TIMER0_OVF0_vect _VECTOR(2)
#define SIG_OVERFLOW0 _VECTOR(2)
#define _VECTORS_SIZE 6
#define INT0 6
#define INTF0 6
#define TOIE0 1
#define TOV0 1
#define SE 5
#define SM 4
#define ISC01 1
#define ISC00 0
#define CS02 2
#define CS01 1
#define CS00 0
#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#define PB2 2
#define PB1 1
#define PB0 0
#define DDB2 2
#define DDB1 1
#define DDB0 0
#define PINB2 2
#define PINB1 1
#define PINB0 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
#define RAMSTART 0x60
#define RAMEND 0xDF
#define XRAMEND RAMEND
#define E2END 0x7F
#define E2PAGESIZE 0
#define FLASHEND 0x07FF
#define FUSE_MEMORY_SIZE 1
#define FUSE_FSTRT (unsigned char)~_BV(0)
#define FUSE_SPIEN (unsigned char)~_BV(5)
#define LFUSE_DEFAULT (0xFF)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x91
#define SIGNATURE_2 0x02
#define SLEEP_MODE_IDLE 0
#define SLEEP_MODE_PWR_DOWN _BV(SM)
#endif
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x91
#define SIGNATURE_2 0x02
