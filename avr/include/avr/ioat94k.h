#ifndef _AVR_IOAT94K_H_
#define _AVR_IOAT94K_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "ioat94k.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define UBRR1 _SFR_IO8(0x00)
#define UCSR1B _SFR_IO8(0x01)
#define UCSR1A _SFR_IO8(0x02)
#define UDR1 _SFR_IO8(0x03)
#define PINE _SFR_IO8(0x05)
#define DDRE _SFR_IO8(0x06)
#define PORTE _SFR_IO8(0x07)
#define OCDR _SFR_IO8(0x08)
#define UBRR0 _SFR_IO8(0x09)
#define UCSR0B _SFR_IO8(0x0A)
#define UCSR0A _SFR_IO8(0x0B)
#define UDR0 _SFR_IO8(0x0C)
#define PIND _SFR_IO8(0x10)
#define DDRD _SFR_IO8(0x11)
#define PORTD _SFR_IO8(0x12)
#define FISCR _SFR_IO8(0x13)
#define FISUA _SFR_IO8(0x14)
#define FISUB _SFR_IO8(0x15)
#define FISUC _SFR_IO8(0x16)
#define FISUD _SFR_IO8(0x17)
#define FPGAX _SFR_IO8(0x18)
#define FPGAY _SFR_IO8(0x19)
#define FPGAZ _SFR_IO8(0x1A)
#define FPGAD _SFR_IO8(0x1B)
#define TWBR _SFR_IO8(0x1C)
#define TWSR _SFR_IO8(0x1D)
#define TWAR _SFR_IO8(0x1E)
#define TWDR _SFR_IO8(0x1F)
#define UBRRH _SFR_IO8(0x20)
#define UBRRHI UBRRH
#define WDTCR _SFR_IO8(0x21)
#define OCR2 _SFR_IO8(0x22)
#define TCNT2 _SFR_IO8(0x23)
#define ICR1 _SFR_IO16(0x24)
#define ICR1L _SFR_IO8(0x24)
#define ICR1H _SFR_IO8(0x25)
#define ASSR _SFR_IO8(0x26)
#define TCCR2 _SFR_IO8(0x27)
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
#define SFIOR _SFR_IO8(0x30)
#define OCR0 _SFR_IO8(0x31)
#define TCNT0 _SFR_IO8(0x32)
#define TCCR0 _SFR_IO8(0x33)
#define MCUR _SFR_IO8(0x35)
#define TWCR _SFR_IO8(0x36)
#define TIFR _SFR_IO8(0x38)
#define TIMSK _SFR_IO8(0x39)
#define SFTCR _SFR_IO8(0x3A)
#define EIMF _SFR_IO8(0x3B)
#define SIG_FPGA_INTERRUPT0 _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(2)
#define SIG_FPGA_INTERRUPT1 _VECTOR(3)
#define SIG_INTERRUPT1 _VECTOR(4)
#define SIG_FPGA_INTERRUPT2 _VECTOR(5)
#define SIG_INTERRUPT2 _VECTOR(6)
#define SIG_FPGA_INTERRUPT3 _VECTOR(7)
#define SIG_INTERRUPT3 _VECTOR(8)
#define SIG_OUTPUT_COMPARE2 _VECTOR(9)
#define SIG_OVERFLOW2 _VECTOR(10)
#define SIG_INPUT_CAPTURE1 _VECTOR(11)
#define SIG_OUTPUT_COMPARE1A _VECTOR(12)
#define SIG_OUTPUT_COMPARE1B _VECTOR(13)
#define SIG_OVERFLOW1 _VECTOR(14)
#define SIG_OUTPUT_COMPARE0 _VECTOR(15)
#define SIG_OVERFLOW0 _VECTOR(16)
#define SIG_FPGA_INTERRUPT4 _VECTOR(17)
#define SIG_FPGA_INTERRUPT5 _VECTOR(18)
#define SIG_FPGA_INTERRUPT6 _VECTOR(19)
#define SIG_FPGA_INTERRUPT7 _VECTOR(20)
#define SIG_UART0_RECV _VECTOR(21)
#define SIG_UART0_DATA _VECTOR(22)
#define SIG_UART0_TRANS _VECTOR(23)
#define SIG_FPGA_INTERRUPT8 _VECTOR(24)
#define SIG_FPGA_INTERRUPT9 _VECTOR(25)
#define SIG_FPGA_INTERRUPT10 _VECTOR(26)
#define SIG_FPGA_INTERRUPT11 _VECTOR(27)
#define SIG_UART1_RECV _VECTOR(28)
#define SIG_UART1_DATA _VECTOR(29)
#define SIG_UART1_TRANS _VECTOR(30)
#define SIG_FPGA_INTERRUPT12 _VECTOR(31)
#define SIG_FPGA_INTERRUPT13 _VECTOR(32)
#define SIG_FPGA_INTERRUPT14 _VECTOR(33)
#define SIG_FPGA_INTERRUPT15 _VECTOR(34)
#define SIG_2WIRE_SERIAL _VECTOR(35)
#define _VECTORS_SIZE 144
#define AS2 3
#define TCN2UB 2
#define OCR2UB 1
#define TCR2UB 0
#define DDD7 7
#define DDD6 6
#define DDD5 5
#define DDD4 4
#define DDD3 3
#define DDD2 2
#define DDD1 1
#define DDD0 0
#define DDE7 7
#define DDE6 6
#define DDE5 5
#define DDE4 4
#define DDE3 3
#define DDE2 2
#define DDE1 1
#define DDE0 0
#define INTF3 7
#define INTF2 6
#define INTF1 5
#define INTF0 4
#define INT3 3
#define INT2 2
#define INT1 1
#define INT0 0
#define FIADR 7
#define XFIS1 1
#define XFIS0 0
#define FIF3 7
#define FIF2 6
#define FIF1 5
#define FIF0 4
#define FINT3 3
#define FINT2 2
#define FINT1 1
#define FINT0 0
#define FIF7 7
#define FIF6 6
#define FIF5 5
#define FIF4 4
#define FINT7 3
#define FINT6 2
#define FINT5 1
#define FINT4 0
#define FIF11 7
#define FIF10 6
#define FIF9 5
#define FIF8 4
#define FINT11 3
#define FINT10 2
#define FINT9 1
#define FINT8 0
#define FIF15 7
#define FIF14 6
#define FIF13 5
#define FIF12 4
#define FINT15 3
#define FINT14 2
#define FINT13 1
#define FINT12 0
#define JTRF 7
#define JTD 6
#define SE 5
#define SM1 4
#define SM0 3
#define PORF 2
#define WDRF 1
#define EXTRF 0
#define IDRD 7
#define PIND7 7
#define PIND6 6
#define PIND5 5
#define PIND4 4
#define PIND3 3
#define PIND2 2
#define PIND1 1
#define PIND0 0
#define PINE7 7
#define PINE6 6
#define PINE5 5
#define PINE4 4
#define PINE3 3
#define PINE2 2
#define PINE1 1
#define PINE0 0
#define PD7 7
#define PD6 6
#define PD5 5
#define PD4 4
#define PD3 3
#define PD2 2
#define PD1 1
#define PD0 0
#define PE7 7
#define PE6 6
#define PE5 5
#define PE4 4
#define PE3 3
#define PE2 2
#define PE1 1
#define PE0 0
#define PSR2 1
#define PSR10 0
#define FMXOR 3
#define WDTS 2
#define DBG 1
#define SRST 0
#define FOC0 7
#define PWM0 6
#define COM01 5
#define COM00 4
#define CTC0 3
#define CS02 2
#define CS01 1
#define CS00 0
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A 3
#define FOC1B 2
#define PWM11 1
#define PWM10 0
#define ICNC1 7
#define ICES1 6
#define ICPE 5
#define CTC1 3
#define CS12 2
#define CS11 1
#define CS10 0
#define FOC2 7
#define PWM2 6
#define COM21 5
#define COM20 4
#define CTC2 3
#define CS22 2
#define CS21 1
#define CS20 0
#define TOV1 7
#define OCF1A 6
#define OCF1B 5
#define TOV2 4
#define ICF1 3
#define OCF2 2
#define TOV0 1
#define OCF0 0
#define TOIE1 7
#define OCIE1A 6
#define OCIE1B 5
#define TOIE2 4
#define TICIE1 3
#define OCIE2 2
#define TOIE0 1
#define OCIE0 0
#define TWGCE 0
#define TWINT 7
#define TWEA 6
#define TWSTA 5
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define RXC0 7
#define TXC0 6
#define UDRE0 5
#define FE0 4
#define OR0 3
#define U2X0 1
#define MPCM0 0
#define RXCIE0 7
#define TXCIE0 6
#define UDRIE0 5
#define RXEN0 4
#define TXEN0 3
#define CHR90 2
#define RXB80 1
#define TXB80 0
#define RXC1 7
#define TXC1 6
#define UDRE1 5
#define FE1 4
#define OR1 3
#define U2X1 1
#define MPCM1 0
#define RXCIE1 7
#define TXCIE1 6
#define UDRIE1 5
#define RXEN1 4
#define TXEN1 3
#define CHR91 2
#define RXB81 1
#define TXB81 0
#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#ifndef RAMSTART
#define RAMSTART 0x60
#endif
#ifndef RAMEND
#define RAMEND 0x0FFF
#endif
#ifndef XRAMEND
#define XRAMEND RAMEND
#endif
#define E2END 0
#ifndef FLASHEND
#define FLASHEND 0x7FFF
#endif
#define SLEEP_MODE_IDLE 0
#define SLEEP_MODE_PWR_DOWN _BV(SM1)
#define SLEEP_MODE_PWR_SAVE (_BV(SM0) | _BV(SM1))
#endif
