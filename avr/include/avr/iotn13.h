#ifndef _AVR_IOTN13_H_
#define _AVR_IOTN13_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iotn13.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define ADCSRB _SFR_IO8(0x03)
# define ACME 6
# define ADTS2 2
# define ADTS1 1
# define ADTS0 0
#ifndef __ASSEMBLER__
#define ADC _SFR_IO16 (0x04)
#endif
#define ADCW _SFR_IO16 (0x04)
#define ADCL _SFR_IO8(0x04)
#define ADCH _SFR_IO8(0x05)
#define ADCSRA _SFR_IO8(0x06)
# define ADEN 7
# define ADSC 6
# define ADATE 5
# define ADIF 4
# define ADIE 3
# define ADPS2 2
# define ADPS1 1
# define ADPS0 0
#define ADMUX _SFR_IO8(0x07)
# define REFS0 6
# define ADLAR 5
# define MUX1 1
# define MUX0 0
#define ACSR _SFR_IO8(0x08)
# define ACD 7
# define ACBG 6
# define ACO 5
# define ACI 4
# define ACIE 3
# define ACIS1 1
# define ACIS0 0
#define DIDR0 _SFR_IO8(0x14)
# define ADC0D 5
# define ADC2D 4
# define ADC3D 3
# define ADC1D 2
# define AIN1D 1
# define AIN0D 0
#define PCMSK _SFR_IO8(0x15)
# define PCINT5 5
# define PCINT4 4
# define PCINT3 3
# define PCINT2 2
# define PCINT1 1
# define PCINT0 0
#define PINB _SFR_IO8(0x16)
# define PINB5 5
# define PINB4 4
# define PINB3 3
# define PINB2 2
# define PINB1 1
# define PINB0 0
#define DDRB _SFR_IO8(0x17)
# define DDB5 5
# define DDB4 4
# define DDB3 3
# define DDB2 2
# define DDB1 1
# define DDB0 0
#define PORTB _SFR_IO8(0x18)
# define PB5 5
# define PB4 4
# define PB3 3
# define PB2 2
# define PB1 1
# define PB0 0
#define EECR _SFR_IO8(0x1C)
#define EEPM1 5
#define EEPM0 4
#define EERIE 3
#define EEMPE 2
#define EEPE 1
#define EERE 0
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO8(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define WDTCR _SFR_IO8(0x21)
# define WDTIF 7
# define WDTIE 6
# define WDP3 5
# define WDCE 4
# define WDE 3
# define WDP2 2
# define WDP1 1
# define WDP0 0
#define CLKPR _SFR_IO8(0x26)
# define CLKPCE 7
# define CLKPS3 3
# define CLKPS2 2
# define CLKPS1 1
# define CLKPS0 0
#define GTCCR _SFR_IO8(0x28)
# define TSM 7
# define PSR10 0
#define OCR0B _SFR_IO8(0x29)
#define DWDR _SFR_IO8(0x2e)
#define TCCR0A _SFR_IO8(0x2f)
# define COM0A1 7
# define COM0A0 6
# define COM0B1 5
# define COM0B0 4
# define WGM01 1
# define WGM00 0
#define OSCCAL _SFR_IO8(0x31)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0B _SFR_IO8(0x33)
# define FOC0A 7
# define FOC0B 6
# define WGM02 3
# define CS02 2
# define CS01 1
# define CS00 0
#define MCUSR _SFR_IO8(0x34)
# define WDRF 3
# define BORF 2
# define EXTRF 1
# define PORF 0
#define MCUCR _SFR_IO8(0x35)
# define PUD 6
# define SE 5
# define SM1 4
# define SM0 3
# define ISC01 1
# define ISC00 0
#define OCR0A _SFR_IO8(0x36)
#define SPMCSR _SFR_IO8(0x37)
# define CTPB 4
# define RFLB 3
# define PGWRT 2
# define PGERS 1
# define SPMEN 0
# define SELFPRGEN 0
#define TIFR0 _SFR_IO8(0x38)
# define OCF0B 3
# define OCF0A 2
# define TOV0 1
#define TIMSK0 _SFR_IO8(0x39)
# define OCIE0B 3
# define OCIE0A 2
# define TOIE0 1
#define GIFR _SFR_IO8(0x3a)
# define INTF0 6
# define PCIF 5
#define GIMSK _SFR_IO8(0x3b)
# define INT0 6
# define PCIE 5
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define PCINT0_vect_num 2
#define PCINT0_vect _VECTOR(2)
#define SIG_PIN_CHANGE0 _VECTOR(2)
#define TIM0_OVF_vect_num 3
#define TIM0_OVF_vect _VECTOR(3)
#define SIG_OVERFLOW0 _VECTOR(3)
#define EE_RDY_vect_num 4
#define EE_RDY_vect _VECTOR(4)
#define SIG_EEPROM_READY _VECTOR(4)
#define ANA_COMP_vect_num 5
#define ANA_COMP_vect _VECTOR(5)
#define SIG_COMPARATOR _VECTOR(5)
#define TIM0_COMPA_vect_num 6
#define TIM0_COMPA_vect _VECTOR(6)
#define SIG_OUTPUT_COMPARE0A _VECTOR(6)
#define TIM0_COMPB_vect_num 7
#define TIM0_COMPB_vect _VECTOR(7)
#define SIG_OUTPUT_COMPARE0B _VECTOR(7)
#define WDT_vect_num 8
#define WDT_vect _VECTOR(8)
#define SIG_WATCHDOG_TIMEOUT _VECTOR(8)
#define ADC_vect_num 9
#define ADC_vect _VECTOR(9)
#define SIG_ADC _VECTOR(9)
#define _VECTORS_SIZE 20
#define SPM_PAGESIZE 32
#define RAMSTART (0x60)
#define RAMEND 0x9F
#define XRAMEND RAMEND
#define E2END 0x3F
#define E2PAGESIZE 4
#define FLASHEND 0x3FF
#define FUSE_MEMORY_SIZE 2
#define FUSE_CKSEL0 (unsigned char)~_BV(0)
#define FUSE_CKSEL1 (unsigned char)~_BV(1)
#define FUSE_SUT0 (unsigned char)~_BV(2)
#define FUSE_SUT1 (unsigned char)~_BV(3)
#define FUSE_CKDIV8 (unsigned char)~_BV(4)
#define FUSE_WDTON (unsigned char)~_BV(5)
#define FUSE_EESAVE (unsigned char)~_BV(6)
#define FUSE_SPIEN (unsigned char)~_BV(7)
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_SUT0 & FUSE_CKDIV8 & FUSE_SPIEN)
#define FUSE_RSTDISBL (unsigned char)~_BV(0)
#define FUSE_BODLEVEL0 (unsigned char)~_BV(1)
#define FUSE_BODLEVEL1 (unsigned char)~_BV(2)
#define FUSE_DWEN (unsigned char)~_BV(3)
#define FUSE_SPMEN (unsigned char)~_BV(4)
#define HFUSE_DEFAULT (0xFF)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x90
#define SIGNATURE_2 0x07
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)
#pragma GCC system_header
#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_PIN_CHANGE0
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_COMPARATOR
#pragma GCC poison SIG_OUTPUT_COMPARE0A
#pragma GCC poison SIG_OUTPUT_COMPARE0B
#pragma GCC poison SIG_WATCHDOG_TIMEOUT
#pragma GCC poison SIG_ADC
#endif
#define SLEEP_MODE_IDLE (0x00<<3)
#define SLEEP_MODE_ADC (0x01<<3)
#define SLEEP_MODE_PWR_DOWN (0x02<<3)
#endif
