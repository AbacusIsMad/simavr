#ifndef _AVR_IO8534_
#define _AVR_IO8534_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "io8534.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x04)
#endif
#define ADCW _SFR_IO16(0x04)
#define ADCL _SFR_IO8(0x04)
#define ADCH _SFR_IO8(0x05)
#define ADCSR _SFR_IO8(0x06)
#define ADMUX _SFR_IO8(0x07)
#define GIPR _SFR_IO8(0x10)
#define DDRA _SFR_IO8(0x1A)
#define PORTA _SFR_IO8(0x1B)
#define EECR _SFR_IO8(0x1C)
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO16(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define EEARH _SFR_IO8(0x1F)
#define TCNT1 _SFR_IO16(0x2C)
#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1H _SFR_IO8(0x2D)
#define TCCR1 _SFR_IO8(0x2E)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0 _SFR_IO8(0x33)
#define MCUCR _SFR_IO8(0x35)
#define TIFR _SFR_IO8(0x38)
#define TIMSK _SFR_IO8(0x39)
#define GIFR _SFR_IO8(0x3A)
#define GIMSK _SFR_IO8(0x3B)
#define SIG_INTERRUPT0 _VECTOR(1)
#define SIG_INTERRUPT1 _VECTOR(2)
#define SIG_OVERFLOW1 _VECTOR(3)
#define SIG_OVERFLOW0 _VECTOR(4)
#define SIG_ADC _VECTOR(5)
#define SIG_EEPROM_READY _VECTOR(6)
#define _VECTORS_SIZE 14
#define INT1 7
#define INT0 6
#define INTF1 7
#define INTF0 6
#define IPIN1 3
#define IPIN0 2
#define TOIE1 2
#define TOIE0 0
#define TOV1 2
#define TOV0 0
#define SE 6
#define SM 5
#define ISC1 2
#define ISC0 0
#define CS02 2
#define CS01 1
#define CS00 0
#define CS12 2
#define CS11 1
#define CS10 0
#define PA7 7
#define PA6 6
#define PA5 5
#define PA4 4
#define PA3 3
#define PA2 2
#define PA1 1
#define PA0 0
#define DDA7 7
#define DDA6 6
#define DDA5 5
#define DDA4 4
#define DDA3 3
#define DDA2 2
#define DDA1 1
#define DDA0 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
#define RAMSTART 0x60
#define RAMEND 0x15F
#define XRAMEND RAMEND
#define E2END 0x1FF
#define FLASHEND 0x1FFF
#endif
