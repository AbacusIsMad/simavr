#ifndef _AVR_IOTN85_H_
#define _AVR_IOTN85_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iotnx5.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define ADCSRB _SFR_IO8 (0x03)
#define BIN 7
#define ACME 6
#define IPR 5
#define ADTS2 2
#define ADTS1 1
#define ADTS0 0
#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x04)
#endif
#define ADCW _SFR_IO16(0x04)
#define ADCL _SFR_IO8(0x04)
#define ADCH _SFR_IO8(0x05)
#define ADCSRA _SFR_IO8 (0x06)
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
#define ADMUX _SFR_IO8(0x07)
#define REFS1 7
#define REFS0 6
#define ADLAR 5
#define REFS2 4
#define MUX3 3
#define MUX2 2
#define MUX1 1
#define MUX0 0
#define ACSR _SFR_IO8(0x08)
#define ACD 7
#define ACBG 6
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIS1 1
#define ACIS0 0
#define USICR _SFR_IO8(0x0D)
#define USISIE 7
#define USIOIE 6
#define USIWM1 5
#define USIWM0 4
#define USICS1 3
#define USICS0 2
#define USICLK 1
#define USITC 0
#define USISR _SFR_IO8(0x0E)
#define USISIF 7
#define USIOIF 6
#define USIPF 5
#define USIDC 4
#define USICNT3 3
#define USICNT2 2
#define USICNT1 1
#define USICNT0 0
#define USIDR _SFR_IO8(0x0F)
#define USIBR _SFR_IO8(0x10)
#define GPIOR0 _SFR_IO8(0x11)
#define GPIOR1 _SFR_IO8(0x12)
#define GPIOR2 _SFR_IO8(0x13)
#define DIDR0 _SFR_IO8(0x14)
#define ADC0D 5
#define ADC2D 4
#define ADC3D 3
#define ADC1D 2
#define AIN1D 1
#define AIN0D 0
#define PCMSK _SFR_IO8(0x15)
#define PCINT5 5
#define PCINT4 4
#define PCINT3 3
#define PCINT2 2
#define PCINT1 1
#define PCINT0 0
#define PINB _SFR_IO8(0x16)
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0
#define DDRB _SFR_IO8(0x17)
#define DDB5 5
#define DDB4 4
#define DDB3 3
#define DDB2 2
#define DDB1 1
#define DDB0 0
#define PORTB _SFR_IO8(0x18)
#define PB5 5
#define PB4 4
#define PB3 3
#define PB2 2
#define PB1 1
#define PB0 0
#define EECR _SFR_IO8(0x1C)
#define EEPM1 5
#define EEPM0 4
#define EERIE 3
#define EEMPE 2
#define EEPE 1
#define EERE 0
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO16(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define EEARH _SFR_IO8(0x1F)
#define PRR _SFR_IO8(0x20)
#define PRTIM1 3
#define PRTIM0 2
#define PRUSI 1
#define PRADC 0
#define __AVR_HAVE_PRR ((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1
#define WDTCR _SFR_IO8(0x21)
#define WDIF 7
#define WDIE 6
#define WDP3 5
#define WDCE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#define DWDR _SFR_IO8(0x22)
#define DTPS1 _SFR_IO8(0x23)
#define DTPS11 1
#define DTPS10 0
#define DT1B _SFR_IO8(0x24)
#define DT1BH3 7
#define DT1BH2 6
#define DT1BH1 5
#define DT1BH0 4
#define DT1BL3 3
#define DT1BL2 2
#define DT1BL1 1
#define DT1BL0 0
#define DT1A _SFR_IO8(0x25)
#define DT1AH3 7
#define DT1AH2 6
#define DT1AH1 5
#define DT1AH0 4
#define DT1AL3 3
#define DT1AL2 2
#define DT1AL1 1
#define DT1AL0 0
#define CLKPR _SFR_IO8(0x26)
#define CLKPCE 7
#define CLKPS3 3
#define CLKPS2 2
#define CLKPS1 1
#define CLKPS0 0
#define PLLCSR _SFR_IO8(0x27)
#define LSM 7
#define PCKE 2
#define PLLE 1
#define PLOCK 0
#define OCR0B _SFR_IO8(0x28)
#define OCR0A _SFR_IO8(0x29)
#define TCCR0A _SFR_IO8(0x2A)
#define COM0A1 7
#define COM0A0 6
#define COM0B1 5
#define COM0B0 4
#define WGM01 1
#define WGM00 0
#define OCR1B _SFR_IO8(0x2B)
#define GTCCR _SFR_IO8(0x2C)
#define TSM 7
#define PWM1B 6
#define COM1B1 5
#define COM1B0 4
#define FOC1B 3
#define FOC1A 2
#define PSR1 1
#define PSR0 0
#define OCR1C _SFR_IO8(0x2D)
#define OCR1A _SFR_IO8(0x2E)
#define TCNT1 _SFR_IO8(0x2F)
#define TCCR1 _SFR_IO8(0x30)
#define CTC1 7
#define PWM1A 6
#define COM1A1 5
#define COM1A0 4
#define CS13 3
#define CS12 2
#define CS11 1
#define CS10 0
#define OSCCAL _SFR_IO8(0x31)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0B _SFR_IO8(0x33)
#define FOC0A 7
#define FOC0B 6
#define WGM02 3
#define CS02 2
#define CS01 1
#define CS00 0
#define MCUSR _SFR_IO8(0x34)
#define WDRF 3
#define BORF 2
#define EXTRF 1
#define PORF 0
#define MCUCR _SFR_IO8(0x35)
#define BODS 7
#define PUD 6
#define SE 5
#define SM1 4
#define SM0 3
#define BODSE 2
#define ISC01 1
#define ISC00 0
#define SPMCSR _SFR_IO8(0x37)
#define RSIG 5
#define CTPB 4
#define RFLB 3
#define PGWRT 2
#define PGERS 1
#define SPMEN 0
#define TIFR _SFR_IO8(0x38)
#define OCF1A 6
#define OCF1B 5
#define OCF0A 4
#define OCF0B 3
#define TOV1 2
#define TOV0 1
#define TIMSK _SFR_IO8(0x39)
#define OCIE1A 6
#define OCIE1B 5
#define OCIE0A 4
#define OCIE0B 3
#define TOIE1 2
#define TOIE0 1
#define GIFR _SFR_IO8(0x3A)
#define INTF0 6
#define PCIF 5
#define GIMSK _SFR_IO8(0x3B)
#define INT0 6
#define PCIE 5
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define PCINT0_vect_num 2
#define PCINT0_vect _VECTOR(2)
#define SIG_PIN_CHANGE _VECTOR(2)
#define TIM1_COMPA_vect_num 3
#define TIM1_COMPA_vect _VECTOR(3)
#define TIMER1_COMPA_vect_num 3
#define TIMER1_COMPA_vect _VECTOR(3)
#define SIG_OUTPUT_COMPARE1A _VECTOR(3)
#define TIM1_OVF_vect_num 4
#define TIM1_OVF_vect _VECTOR(4)
#define TIMER1_OVF_vect_num 4
#define TIMER1_OVF_vect _VECTOR(4)
#define SIG_OVERFLOW1 _VECTOR(4)
#define TIM0_OVF_vect_num 5
#define TIM0_OVF_vect _VECTOR(5)
#define TIMER0_OVF_vect_num 5
#define TIMER0_OVF_vect _VECTOR(5)
#define SIG_OVERFLOW0 _VECTOR(5)
#define EE_RDY_vect_num 6
#define EE_RDY_vect _VECTOR(6)
#define SIG_EEPROM_READY _VECTOR(6)
#define ANA_COMP_vect_num 7
#define ANA_COMP_vect _VECTOR(7)
#define SIG_COMPARATOR _VECTOR(7)
#define ADC_vect_num 8
#define ADC_vect _VECTOR(8)
#define SIG_ADC _VECTOR(8)
#define TIM1_COMPB_vect_num 9
#define TIM1_COMPB_vect _VECTOR(9)
#define TIMER1_COMPB_vect_num 9
#define TIMER1_COMPB_vect _VECTOR(9)
#define SIG_OUTPUT_COMPARE1B _VECTOR(9)
#define TIM0_COMPA_vect_num 10
#define TIM0_COMPA_vect _VECTOR(10)
#define TIMER0_COMPA_vect_num 10
#define TIMER0_COMPA_vect _VECTOR(10)
#define SIG_OUTPUT_COMPARE0A _VECTOR(10)
#define TIM0_COMPB_vect_num 11
#define TIM0_COMPB_vect _VECTOR(11)
#define TIMER0_COMPB_vect_num 11
#define TIMER0_COMPB_vect _VECTOR(11)
#define SIG_OUTPUT_COMPARE0B _VECTOR(11)
#define WDT_vect_num 12
#define WDT_vect _VECTOR(12)
#define SIG_WATCHDOG_TIMEOUT _VECTOR(12)
#define USI_START_vect_num 13
#define USI_START_vect _VECTOR(13)
#define SIG_USI_START _VECTOR(13)
#define USI_OVF_vect_num 14
#define USI_OVF_vect _VECTOR(14)
#define SIG_USI_OVERFLOW _VECTOR(14)
#define _VECTORS_SIZE 30
#define SPM_PAGESIZE 64
#define RAMSTART (0x60)
#define RAMEND 0x25F
#define XRAMEND RAMEND
#define E2END 0x1FF
#define E2PAGESIZE 4
#define FLASHEND 0x1FFF
#define FUSE_MEMORY_SIZE 3
#define FUSE_CKSEL0 (unsigned char)~_BV(0)
#define FUSE_CKSEL1 (unsigned char)~_BV(1)
#define FUSE_CKSEL2 (unsigned char)~_BV(2)
#define FUSE_CKSEL3 (unsigned char)~_BV(3)
#define FUSE_SUT0 (unsigned char)~_BV(4)
#define FUSE_SUT1 (unsigned char)~_BV(5)
#define FUSE_CKOUT (unsigned char)~_BV(6)
#define FUSE_CKDIV8 (unsigned char)~_BV(7)
#define LFUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3 & FUSE_SUT0 & FUSE_CKDIV8)
#define FUSE_BODLEVEL0 (unsigned char)~_BV(0)
#define FUSE_BODLEVEL1 (unsigned char)~_BV(1)
#define FUSE_BODLEVEL2 (unsigned char)~_BV(2)
#define FUSE_EESAVE (unsigned char)~_BV(3)
#define FUSE_WDTON (unsigned char)~_BV(4)
#define FUSE_SPIEN (unsigned char)~_BV(5)
#define FUSE_DWEN (unsigned char)~_BV(6)
#define FUSE_RSTDISBL (unsigned char)~_BV(7)
#define HFUSE_DEFAULT (FUSE_SPIEN)
#define FUSE_SELFPRGEN (unsigned char)~_BV(0)
#define EFUSE_DEFAULT (0xFF)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x93
#define SIGNATURE_2 0x0B
#define SLEEP_MODE_IDLE (0x00<<3)
#define SLEEP_MODE_ADC (0x01<<3)
#define SLEEP_MODE_PWR_DOWN (0x02<<3)
#endif
