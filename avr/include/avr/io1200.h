#ifndef _AVR_IO1200_H_
#define _AVR_IO1200_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "io1200.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef __ASSEMBLER__
# warning "MCU not supported by the C compiler"
#endif
#define ACSR _SFR_IO8(0x08)
#define PIND _SFR_IO8(0x10)
#define DDRD _SFR_IO8(0x11)
#define PORTD _SFR_IO8(0x12)
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
#define MCUCR _SFR_IO8(0x35)
#define TIFR _SFR_IO8(0x38)
#define TIMSK _SFR_IO8(0x39)
#define GIMSK _SFR_IO8(0x3B)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define TIMER0_OVF_vect_num 2
#define TIMER0_OVF_vect _VECTOR(2)
#define SIG_OVERFLOW0 _VECTOR(2)
#define ANA_COMP_vect_num 3
#define ANA_COMP_vect _VECTOR(3)
#define SIG_COMPARATOR _VECTOR(3)
#define _VECTORS_SIZE 8
#define INT0 6
#define TOIE0 1
#define TOV0 1
#define SE 5
#define SM 4
#define ISC01 1
#define ISC00 0
#define CS02 2
#define CS01 1
#define CS00 0
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#undef EEMWE
#define PB7 7
#define PB6 6
#define PB5 5
#define PB4 4
#define PB3 3
#define PB2 2
#define PB1 1
#define PB0 0
#define DDB7 7
#define DDB6 6
#define DDB5 5
#define DDB4 4
#define DDB3 3
#define DDB2 2
#define DDB1 1
#define DDB0 0
#define PINB7 7
#define PINB6 6
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0
#define PD6 6
#define PD5 5
#define PD4 4
#define PD3 3
#define PD2 2
#define PD1 1
#define PD0 0
#define DDD6 6
#define DDD5 5
#define DDD4 4
#define DDD3 3
#define DDD2 2
#define DDD1 1
#define DDD0 0
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0
#define ACD 7
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIS1 1
#define ACIS0 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
#undef ZH
#define RAMSTART 0x60
#define RAMEND 0x1F
#define XRAMEND 0x0
#define E2END 0x3F
#define E2PAGESIZE 0
#define FLASHEND 0x3FF
#define FUSE_MEMORY_SIZE 1
#define FUSE_RCEN (unsigned char)~_BV(0)
#define FUSE_SPIEN (unsigned char)~_BV(5)
#define LFUSE_DEFAULT (0xFF)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x90
#define SIGNATURE_2 0x01
#endif
