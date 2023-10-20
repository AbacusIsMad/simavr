#ifndef _AVR_IOTN12_H_
#define _AVR_IOTN12_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iotn12.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef __ASSEMBLER__
# warning "MCU not supported by the C compiler"
#endif
#define ACSR _SFR_IO8(0x08)
#define PINB _SFR_IO8(0x16)
#define DDRB _SFR_IO8(0x17)
#define PORTB _SFR_IO8(0x18)
#define EECR _SFR_IO8(0x1C)
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO8(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define WDTCR _SFR_IO8(0x21)
#define OSCCAL _SFR_IO8(0x31)
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
#define IO_PINS_vect_num 2
#define IO_PINS_vect _VECTOR(2)
#define SIG_PIN _VECTOR(2)
#define SIG_PIN_CHANGE _VECTOR(2)
#define TIMER0_OVF_vect_num 3
#define TIMER0_OVF_vect _VECTOR(3)
#define SIG_OVERFLOW0 _VECTOR(3)
#define EE_RDY_vect_num 4
#define EE_RDY_vect _VECTOR(4)
#define SIG_EEPROM_READY _VECTOR(4)
#define ANA_COMP_vect_num 5
#define ANA_COMP_vect _VECTOR(5)
#define SIG_COMPARATOR _VECTOR(5)
#define _VECTORS_SIZE 12
#define INT0 6
#define PCIE 5
#define INTF0 6
#define PCIF 5
#define TOIE0 1
#define TOV0 1
#define PUD 6
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
#define PB4 4
#define PB3 3
#define PB2 2
#define PB1 1
#define PB0 0
#define DDB5 5
#define DDB4 4
#define DDB3 3
#define DDB2 2
#define DDB1 1
#define DDB0 0
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0
#define ACD 7
#define AINBG 6
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIS1 1
#define ACIS0 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
#define RAMSTART 0x60
#define RAMEND 0x1F
#define XRAMEND 0x0
#define E2END 0x3F
#define E2PAGESIZE 2
#define FLASHEND 0x3FF
#define FUSE_MEMORY_SIZE 1
#define FUSE_CKSEL0 (unsigned char)~_BV(0)
#define FUSE_CKSEL1 (unsigned char)~_BV(1)
#define FUSE_CKSEL2 (unsigned char)~_BV(2)
#define FUSE_CKSEL3 (unsigned char)~_BV(3)
#define FUSE_RSTDISBL (unsigned char)~_BV(4)
#define FUSE_SPIEN (unsigned char)~_BV(5)
#define FUSE_BODEN (unsigned char)~_BV(6)
#define FUSE_BODLEVEL (unsigned char)~_BV(7)
#define FUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SPIEN & FUSE_BODLEVEL)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x90
#define SIGNATURE_2 0x05
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)
#pragma GCC system_header
#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_PIN
#pragma GCC poison SIG_PIN_CHANGE
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_COMPARATOR
#endif
#define SLEEP_MODE_IDLE (0x00<<4)
#define SLEEP_MODE_PWR_DOWN (0x01<<4)
#endif
