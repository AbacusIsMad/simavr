#ifndef _AVR_IOM103_H_
#define _AVR_IOM103_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iom103.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define PINF _SFR_IO8(0x00)
#define PINE _SFR_IO8(0x01)
#define DDRE _SFR_IO8(0x02)
#define PORTE _SFR_IO8(0x03)
#ifndef __ASSEMBLER__
#define ADC _SFR_IO16(0x04)
#endif
#define ADCW _SFR_IO16(0x04)
#define ADCL _SFR_IO8(0x04)
#define ADCH _SFR_IO8(0x05)
#define ADCSR _SFR_IO8(0x06)
#define ADMUX _SFR_IO8(0x07)
#define ACSR _SFR_IO8(0x08)
#define UBRR _SFR_IO8(0x09)
#define UCR _SFR_IO8(0x0A)
#define USR _SFR_IO8(0x0B)
#define UDR _SFR_IO8(0x0C)
#define SPCR _SFR_IO8(0x0D)
#define SPSR _SFR_IO8(0x0E)
#define SPDR _SFR_IO8(0x0F)
#define PIND _SFR_IO8(0x10)
#define DDRD _SFR_IO8(0x11)
#define PORTD _SFR_IO8(0x12)
#define PORTC _SFR_IO8(0x15)
#define PINB _SFR_IO8(0x16)
#define DDRB _SFR_IO8(0x17)
#define PORTB _SFR_IO8(0x18)
#define PINA _SFR_IO8(0x19)
#define DDRA _SFR_IO8(0x1A)
#define PORTA _SFR_IO8(0x1B)
#define EECR _SFR_IO8(0x1C)
#define EEDR _SFR_IO8(0x1D)
#define EEAR _SFR_IO16(0x1E)
#define EEARL _SFR_IO8(0x1E)
#define EEARH _SFR_IO8(0x1F)
#define WDTCR _SFR_IO8(0x21)
#define OCR2 _SFR_IO8(0x23)
#define TCNT2 _SFR_IO8(0x24)
#define TCCR2 _SFR_IO8(0x25)
#define ICR1 _SFR_IO16(0x26)
#define ICR1L _SFR_IO8(0x26)
#define ICR1H _SFR_IO8(0x27)
#define OCR1B _SFR_IO16(0x28)
#define OCR1BL _SFR_IO8(0x28)
#define OCR1BH _SFR_IO8(0x29)
#define OCR1A _SFR_IO16(0x2A)
#define OCR1AL _SFR_IO8(0x2A)
#define OCR1AH _SFR_IO8(0x2B)
#define TCNT1 _SFR_IO16(0x2C)
#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1H _SFR_IO8(0x2D)
#define TCCR1B _SFR_IO8(0x2E)
#define TCCR1A _SFR_IO8(0x2F)
#define ASSR _SFR_IO8(0x30)
#define OCR0 _SFR_IO8(0x31)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0 _SFR_IO8(0x33)
#define MCUSR _SFR_IO8(0x34)
#define MCUCR _SFR_IO8(0x35)
#define TIFR _SFR_IO8(0x36)
#define TIMSK _SFR_IO8(0x37)
#define EIFR _SFR_IO8(0x38)
#define EIMSK _SFR_IO8(0x39)
#define EICR _SFR_IO8(0x3A)
#define RAMPZ _SFR_IO8(0x3B)
#define XDIV _SFR_IO8(0x3C)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define INT1_vect_num 2
#define INT1_vect _VECTOR(2)
#define SIG_INTERRUPT1 _VECTOR(2)
#define INT2_vect_num 3
#define INT2_vect _VECTOR(3)
#define SIG_INTERRUPT2 _VECTOR(3)
#define INT3_vect_num 4
#define INT3_vect _VECTOR(4)
#define SIG_INTERRUPT3 _VECTOR(4)
#define INT4_vect_num 5
#define INT4_vect _VECTOR(5)
#define SIG_INTERRUPT4 _VECTOR(5)
#define INT5_vect_num 6
#define INT5_vect _VECTOR(6)
#define SIG_INTERRUPT5 _VECTOR(6)
#define INT6_vect_num 7
#define INT6_vect _VECTOR(7)
#define SIG_INTERRUPT6 _VECTOR(7)
#define INT7_vect_num 8
#define INT7_vect _VECTOR(8)
#define SIG_INTERRUPT7 _VECTOR(8)
#define TIMER2_COMP_vect_num 9
#define TIMER2_COMP_vect _VECTOR(9)
#define SIG_OUTPUT_COMPARE2 _VECTOR(9)
#define TIMER2_OVF_vect_num 10
#define TIMER2_OVF_vect _VECTOR(10)
#define SIG_OVERFLOW2 _VECTOR(10)
#define TIMER1_CAPT_vect_num 11
#define TIMER1_CAPT_vect _VECTOR(11)
#define SIG_INPUT_CAPTURE1 _VECTOR(11)
#define TIMER1_COMPA_vect_num 12
#define TIMER1_COMPA_vect _VECTOR(12)
#define SIG_OUTPUT_COMPARE1A _VECTOR(12)
#define TIMER1_COMPB_vect_num 13
#define TIMER1_COMPB_vect _VECTOR(13)
#define SIG_OUTPUT_COMPARE1B _VECTOR(13)
#define TIMER1_OVF_vect_num 14
#define TIMER1_OVF_vect _VECTOR(14)
#define SIG_OVERFLOW1 _VECTOR(14)
#define TIMER0_COMP_vect_num 15
#define TIMER0_COMP_vect _VECTOR(15)
#define SIG_OUTPUT_COMPARE0 _VECTOR(15)
#define TIMER0_OVF_vect_num 16
#define TIMER0_OVF_vect _VECTOR(16)
#define SIG_OVERFLOW0 _VECTOR(16)
#define SPI_STC_vect_num 17
#define SPI_STC_vect _VECTOR(17)
#define SIG_SPI _VECTOR(17)
#define UART_RX_vect_num 18
#define UART_RX_vect _VECTOR(18)
#define SIG_UART_RECV _VECTOR(18)
#define UART_UDRE_vect_num 19
#define UART_UDRE_vect _VECTOR(19)
#define SIG_UART_DATA _VECTOR(19)
#define UART_TX_vect_num 20
#define UART_TX_vect _VECTOR(20)
#define SIG_UART_TRANS _VECTOR(20)
#define ADC_vect_num 21
#define ADC_vect _VECTOR(21)
#define SIG_ADC _VECTOR(21)
#define EE_READY_vect_num 22
#define EE_READY_vect _VECTOR(22)
#define SIG_EEPROM_READY _VECTOR(22)
#define ANALOG_COMP_vect_num 23
#define ANALOG_COMP_vect _VECTOR(23)
#define SIG_COMPARATOR _VECTOR(23)
#define _VECTORS_SIZE 96
#define XDIVEN 7
#define XDIV6 6
#define XDIV5 5
#define XDIV4 4
#define XDIV3 3
#define XDIV2 2
#define XDIV1 1
#define XDIV0 0
#define RAMPZ0 0
#define ISC71 7
#define ISC70 6
#define ISC61 5
#define ISC60 4
#define ISC51 3
#define ISC50 2
#define ISC41 1
#define ISC40 0
#define INT7 7
#define INT6 6
#define INT5 5
#define INT4 4
#define INT3 3
#define INT2 2
#define INT1 1
#define INT0 0
#define INTF7 7
#define INTF6 6
#define INTF5 5
#define INTF4 4
#define OCIE2 7
#define TOIE2 6
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1 2
#define OCIE0 1
#define TOIE0 0
#define OCF2 7
#define TOV2 6
#define ICF1 5
#define OCF1A 4
#define OCF1B 3
#define TOV1 2
#define OCF0 1
#define TOV0 0
#define SRE 7
#define SRW 6
#define SE 5
#define SM1 4
#define SM0 3
#define EXTRF 1
#define PORF 0
#define PWM0 6
#define COM01 5
#define COM00 4
#define CTC0 3
#define CS02 2
#define CS01 1
#define CS00 0
#define AS0 3
#define TCN0UB 2
#define OCR0UB 1
#define TCR0UB 0
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define PWM11 1
#define PWM10 0
#define ICNC1 7
#define ICES1 6
#define CTC1 3
#define CS12 2
#define CS11 1
#define CS10 0
#define PWM2 6
#define COM21 5
#define COM20 4
#define CTC2 3
#define CS22 2
#define CS21 1
#define CS20 0
#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
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
#define PINA7 7
#define PINA6 6
#define PINA5 5
#define PINA4 4
#define PINA3 3
#define PINA2 2
#define PINA1 1
#define PINA0 0
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
#define PC7 7
#define PC6 6
#define PC5 5
#define PC4 4
#define PC3 3
#define PC2 2
#define PC1 1
#define PC0 0
#define PD7 7
#define PD6 6
#define PD5 5
#define PD4 4
#define PD3 3
#define PD2 2
#define PD1 1
#define PD0 0
#define DDD7 7
#define DDD6 6
#define DDD5 5
#define DDD4 4
#define DDD3 3
#define DDD2 2
#define DDD1 1
#define DDD0 0
#define PIND7 7
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0
#define PE7 7
#define PE6 6
#define PE5 5
#define PE4 4
#define PE3 3
#define PE2 2
#define PE1 1
#define PE0 0
#define DDE7 7
#define DDE6 6
#define DDE5 5
#define DDE4 4
#define DDE3 3
#define DDE2 2
#define DDE1 1
#define DDE0 0
#define PINE7 7
#define PINE6 6
#define PINE5 5
#define PINE4 4
#define PINE3 3
#define PINE2 2
#define PINE1 1
#define PINE0 0
#define PINF7 7
#define PINF6 6
#define PINF5 5
#define PINF4 4
#define PINF3 3
#define PINF2 2
#define PINF1 1
#define PINF0 0
#define SPIF 7
#define WCOL 6
#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define CHR9 2
#define RXB8 1
#define TXB8 0
#define ACD 7
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIC 2
#define ACIS1 1
#define ACIS0 0
#define ADEN 7
#define ADSC 6
#define ADFR 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0
#define MUX2 2
#define MUX1 1
#define MUX0 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
#define RAMSTART 0x60
#define RAMEND 0x0FFF
#define XRAMEND 0xFFFF
#define E2END 0x0FFF
#define E2PAGESIZE 0
#define FLASHEND 0x1FFFF
#define FUSE_MEMORY_SIZE 1
#define FUSE_CKSEL0 (unsigned char)~_BV(0)
#define FUSE_CKSEL1 (unsigned char)~_BV(1)
#define FUSE_CKSEL2 (unsigned char)~_BV(2)
#define FUSE_CKSEL3 (unsigned char)~_BV(3)
#define FUSE_SUT0 (unsigned char)~_BV(4)
#define FUSE_SUT1 (unsigned char)~_BV(5)
#define FUSE_BODEN (unsigned char)~_BV(6)
#define FUSE_BODLEVEL (unsigned char)~_BV(7)
#define LFUSE_DEFAULT (FUSE_SUT1 & FUSE_SUT0 & FUSE_CKSEL3 & FUSE_CKSEL2 & FUSE_CKSEL1)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x01
#define SLEEP_MODE_IDLE 0
#define SLEEP_MODE_ADC _BV(SM0)
#define SLEEP_MODE_PWR_DOWN _BV(SM1)
#define SLEEP_MODE_PWR_SAVE (_BV(SM0) | _BV(SM1))
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)
#pragma GCC system_header
#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_INTERRUPT2
#pragma GCC poison SIG_INTERRUPT3
#pragma GCC poison SIG_INTERRUPT4
#pragma GCC poison SIG_INTERRUPT5
#pragma GCC poison SIG_INTERRUPT6
#pragma GCC poison SIG_INTERRUPT7
#pragma GCC poison SIG_OUTPUT_COMPARE2
#pragma GCC poison SIG_OVERFLOW2
#pragma GCC poison SIG_INPUT_CAPTURE1
#pragma GCC poison SIG_OUTPUT_COMPARE1A
#pragma GCC poison SIG_OUTPUT_COMPARE1B
#pragma GCC poison SIG_OVERFLOW1
#pragma GCC poison SIG_OUTPUT_COMPARE0
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_SPI
#pragma GCC poison SIG_UART_RECV
#pragma GCC poison SIG_UART_DATA
#pragma GCC poison SIG_UART_TRANS
#pragma GCC poison SIG_ADC
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_COMPARATOR
#endif
#endif
