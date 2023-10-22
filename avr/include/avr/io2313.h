#ifndef _AVR_IO2313_H_
#define _AVR_IO2313_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "io2313.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define ACSR _SFR_IO8(0x08)
#define UBRR _SFR_IO8(0x09)
#define UCR _SFR_IO8(0x0A)
#define USR _SFR_IO8(0x0B)
#define UDR _SFR_IO8(0x0C)
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
#define ICR1 _SFR_IO16(0x24)
#define ICR1L _SFR_IO8(0x24)
#define ICR1H _SFR_IO8(0x25)
#define OCR1 _SFR_IO16(0x2A)
#define OCR1L _SFR_IO8(0x2A)
#define OCR1H _SFR_IO8(0x2B)
#define OCR1A _SFR_IO16(0x2A)
#define OCR1AL _SFR_IO8(0x2A)
#define OCR1AH _SFR_IO8(0x2B)
#define TCNT1 _SFR_IO16(0x2C)
#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1H _SFR_IO8(0x2D)
#define TCCR1B _SFR_IO8(0x2E)
#define TCCR1A _SFR_IO8(0x2F)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0 _SFR_IO8(0x33)
#define MCUCR _SFR_IO8(0x35)
#define TIFR _SFR_IO8(0x38)
#define TIMSK _SFR_IO8(0x39)
#define GIFR _SFR_IO8(0x3A)
#define GIMSK _SFR_IO8(0x3B)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define INT1_vect_num 2
#define INT1_vect _VECTOR(2)
#define SIG_INTERRUPT1 _VECTOR(2)
#define TIMER1_CAPT1_vect_num 3
#define TIMER1_CAPT1_vect _VECTOR(3)
#define SIG_INPUT_CAPTURE1 _VECTOR(3)
#define TIMER1_COMP1_vect_num 4
#define TIMER1_COMP1_vect _VECTOR(4)
#define SIG_OUTPUT_COMPARE1A _VECTOR(4)
#define TIMER1_OVF1_vect_num 5
#define TIMER1_OVF1_vect _VECTOR(5)
#define SIG_OVERFLOW1 _VECTOR(5)
#define TIMER0_OVF0_vect_num 6
#define TIMER0_OVF0_vect _VECTOR(6)
#define SIG_OVERFLOW0 _VECTOR(6)
#define UART_RX_vect_num 7
#define UART_RX_vect _VECTOR(7)
#define SIG_UART_RECV _VECTOR(7)
#define UART_UDRE_vect_num 8
#define UART_UDRE_vect _VECTOR(8)
#define SIG_UART_DATA _VECTOR(8)
#define UART_TX_vect_num 9
#define UART_TX_vect _VECTOR(9)
#define SIG_UART_TRANS _VECTOR(9)
#define ANA_COMP_vect_num 10
#define ANA_COMP_vect _VECTOR(10)
#define SIG_COMPARATOR _VECTOR(10)
#define _VECTORS_SIZE 22
#define INT1 7
#define INT0 6
#define INTF1 7
#define INTF0 6
#define TOIE1 7
#define OCIE1A 6
#define TICIE 3
#define TICIE1 3
#define TOIE0 1
#define TOV1 7
#define OCF1A 6
#define ICF1 3
#define TOV0 1
#define SE 5
#define SM 4
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0
#define CS02 2
#define CS01 1
#define CS00 0
#define COM1A1 7
#define COM1A0 6
#define PWM11 1
#define PWM10 0
#define ICNC1 7
#define ICES1 6
#define CTC1 3
#define CS12 2
#define CS11 1
#define CS10 0
#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#define EEMWE 2
#define EEWE 1
#define EERE 0
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
#define SIGNATURE_2 0x01
#define SLEEP_MODE_IDLE 0
#define SLEEP_MODE_PWR_DOWN _BV(SM)
#endif