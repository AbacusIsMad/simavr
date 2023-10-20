#ifndef _AVR_IOM162_H_
#define _AVR_IOM162_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iom162.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#define TCCR3A _SFR_MEM8(0x8B)
#define TCCR3B _SFR_MEM8(0x8A)
#define TCNT3H _SFR_MEM8(0x89)
#define TCNT3L _SFR_MEM8(0x88)
#define TCNT3 _SFR_MEM16(0x88)
#define OCR3AH _SFR_MEM8(0x87)
#define OCR3AL _SFR_MEM8(0x86)
#define OCR3A _SFR_MEM16(0x86)
#define OCR3BH _SFR_MEM8(0x85)
#define OCR3BL _SFR_MEM8(0x84)
#define OCR3B _SFR_MEM16(0x84)
#define ICR3H _SFR_MEM8(0x81)
#define ICR3L _SFR_MEM8(0x80)
#define ICR3 _SFR_MEM16(0x80)
#define ETIMSK _SFR_MEM8(0x7D)
#define ETIFR _SFR_MEM8(0x7C)
#define PCMSK1 _SFR_MEM8(0x6C)
#define PCMSK0 _SFR_MEM8(0x6B)
#define CLKPR _SFR_MEM8(0x61)
#define UBRR1H _SFR_IO8(0x3C)
#define UCSR1C _SFR_IO8(0x3C)
#define GICR _SFR_IO8(0x3B)
#define GIFR _SFR_IO8(0x3A)
#define TIMSK _SFR_IO8(0x39)
#define TIFR _SFR_IO8(0x38)
#define SPMCR _SFR_IO8(0x37)
#define EMCUCR _SFR_IO8(0x36)
#define MCUCR _SFR_IO8(0x35)
#define MCUCSR _SFR_IO8(0x34)
#define TCCR0 _SFR_IO8(0x33)
#define TCNT0 _SFR_IO8(0x32)
#define OCR0 _SFR_IO8(0x31)
#define SFIOR _SFR_IO8(0x30)
#define TCCR1A _SFR_IO8(0x2F)
#define TCCR1B _SFR_IO8(0x2E)
#define TCNT1H _SFR_IO8(0x2D)
#define TCNT1L _SFR_IO8(0x2C)
#define TCNT1 _SFR_IO16(0x2C)
#define OCR1AH _SFR_IO8(0x2B)
#define OCR1AL _SFR_IO8(0x2A)
#define OCR1A _SFR_IO16(0x2A)
#define OCR1BH _SFR_IO8(0x29)
#define OCR1BL _SFR_IO8(0x28)
#define OCR1B _SFR_IO16(0x28)
#define TCCR2 _SFR_IO8(0x27)
#define ASSR _SFR_IO8(0x26)
#define ICR1H _SFR_IO8(0x25)
#define ICR1L _SFR_IO8(0x24)
#define ICR1 _SFR_IO16(0x24)
#define TCNT2 _SFR_IO8(0x23)
#define OCR2 _SFR_IO8(0x22)
#define WDTCR _SFR_IO8(0x21)
#define UBRR0H _SFR_IO8(0x20)
#define UCSR0C _SFR_IO8(0x20)
#define EEARH _SFR_IO8(0x1F)
#define EEARL _SFR_IO8(0x1E)
#define EEAR _SFR_IO16(0x1E)
#define EEDR _SFR_IO8(0x1D)
#define EECR _SFR_IO8(0x1C)
#define PORTA _SFR_IO8(0x1B)
#define DDRA _SFR_IO8(0x1A)
#define PINA _SFR_IO8(0x19)
#define PORTB _SFR_IO8(0x18)
#define DDRB _SFR_IO8(0x17)
#define PINB _SFR_IO8(0x16)
#define PORTC _SFR_IO8(0x15)
#define DDRC _SFR_IO8(0x14)
#define PINC _SFR_IO8(0x13)
#define PORTD _SFR_IO8(0x12)
#define DDRD _SFR_IO8(0x11)
#define PIND _SFR_IO8(0x10)
#define SPDR _SFR_IO8(0x0F)
#define SPSR _SFR_IO8(0x0E)
#define SPCR _SFR_IO8(0x0D)
#define UDR0 _SFR_IO8(0x0C)
#define UCSR0A _SFR_IO8(0x0B)
#define UCSR0B _SFR_IO8(0x0A)
#define UBRR0L _SFR_IO8(0x09)
#define ACSR _SFR_IO8(0x08)
#define PORTE _SFR_IO8(0x07)
#define DDRE _SFR_IO8(0x06)
#define PINE _SFR_IO8(0x05)
#define OSCCAL _SFR_IO8(0x04)
#define OCDR _SFR_IO8(0x04)
#define UDR1 _SFR_IO8(0x03)
#define UCSR1A _SFR_IO8(0x02)
#define UCSR1B _SFR_IO8(0x01)
#define UBRR1L _SFR_IO8(0x00)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define INT1_vect_num 2
#define INT1_vect _VECTOR(2)
#define SIG_INTERRUPT1 _VECTOR(2)
#define INT2_vect_num 3
#define INT2_vect _VECTOR(3)
#define SIG_INTERRUPT2 _VECTOR(3)
#define PCINT0_vect_num 4
#define PCINT0_vect _VECTOR(4)
#define SIG_PIN_CHANGE0 _VECTOR(4)
#define PCINT1_vect_num 5
#define PCINT1_vect _VECTOR(5)
#define SIG_PIN_CHANGE1 _VECTOR(5)
#define TIMER3_CAPT_vect_num 6
#define TIMER3_CAPT_vect _VECTOR(6)
#define SIG_INPUT_CAPTURE3 _VECTOR(6)
#define TIMER3_COMPA_vect_num 7
#define TIMER3_COMPA_vect _VECTOR(7)
#define SIG_OUTPUT_COMPARE3A _VECTOR(7)
#define TIMER3_COMPB_vect_num 8
#define TIMER3_COMPB_vect _VECTOR(8)
#define SIG_OUTPUT_COMPARE3B _VECTOR(8)
#define TIMER3_OVF_vect_num 9
#define TIMER3_OVF_vect _VECTOR(9)
#define SIG_OVERFLOW3 _VECTOR(9)
#define TIMER2_COMP_vect_num 10
#define TIMER2_COMP_vect _VECTOR(10)
#define SIG_OUTPUT_COMPARE2 _VECTOR(10)
#define TIMER2_OVF_vect_num 11
#define TIMER2_OVF_vect _VECTOR(11)
#define SIG_OVERFLOW2 _VECTOR(11)
#define TIMER1_CAPT_vect_num 12
#define TIMER1_CAPT_vect _VECTOR(12)
#define SIG_INPUT_CAPTURE1 _VECTOR(12)
#define TIMER1_COMPA_vect_num 13
#define TIMER1_COMPA_vect _VECTOR(13)
#define SIG_OUTPUT_COMPARE1A _VECTOR(13)
#define TIMER1_COMPB_vect_num 14
#define TIMER1_COMPB_vect _VECTOR(14)
#define SIG_OUTPUT_COMPARE1B _VECTOR(14)
#define TIMER1_OVF_vect_num 15
#define TIMER1_OVF_vect _VECTOR(15)
#define SIG_OVERFLOW1 _VECTOR(15)
#define TIMER0_COMP_vect_num 16
#define TIMER0_COMP_vect _VECTOR(16)
#define SIG_OUTPUT_COMPARE0 _VECTOR(16)
#define TIMER0_OVF_vect_num 17
#define TIMER0_OVF_vect _VECTOR(17)
#define SIG_OVERFLOW0 _VECTOR(17)
#define SPI_STC_vect_num 18
#define SPI_STC_vect _VECTOR(18)
#define SIG_SPI _VECTOR(18)
#define USART0_RXC_vect_num 19
#define USART0_RXC_vect _VECTOR(19)
#define SIG_USART0_RECV _VECTOR(19)
#define USART1_RXC_vect_num 20
#define USART1_RXC_vect _VECTOR(20)
#define SIG_USART1_RECV _VECTOR(20)
#define USART0_UDRE_vect_num 21
#define USART0_UDRE_vect _VECTOR(21)
#define SIG_USART0_DATA _VECTOR(21)
#define USART1_UDRE_vect_num 22
#define USART1_UDRE_vect _VECTOR(22)
#define SIG_USART1_DATA _VECTOR(22)
#define USART0_TXC_vect_num 23
#define USART0_TXC_vect _VECTOR(23)
#define SIG_USART0_TRANS _VECTOR(23)
#define USART1_TXC_vect_num 24
#define USART1_TXC_vect _VECTOR(24)
#define SIG_USART1_TRANS _VECTOR(24)
#define EE_RDY_vect_num 25
#define EE_RDY_vect _VECTOR(25)
#define SIG_EEPROM_READY _VECTOR(25)
#define ANA_COMP_vect_num 26
#define ANA_COMP_vect _VECTOR(26)
#define SIG_COMPARATOR _VECTOR(26)
#define SPM_RDY_vect_num 27
#define SPM_RDY_vect _VECTOR(27)
#define SIG_SPM_READY _VECTOR(27)
#define _VECTORS_SIZE 112
#define ICNC3 7
#define ICES3 6
#define WGM33 4
#define WGM32 3
#define CS32 2
#define CS31 1
#define CS30 0
#define COM3A1 7
#define COM3A0 6
#define COM3B1 5
#define COM3B0 4
#define FOC3A 3
#define FOC3B 2
#define WGM31 1
#define WGM30 0
#define TICIE3 5
#define OCIE3A 4
#define OCIE3B 3
#define TOIE3 2
#define ICF3 5
#define OCF3A 4
#define OCF3B 3
#define TOV3 2
#define PCINT15 7
#define PCINT14 6
#define PCINT13 5
#define PCINT12 4
#define PCINT11 3
#define PCINT10 2
#define PCINT9 1
#define PCINT8 0
#define PCINT7 7
#define PCINT6 6
#define PCINT5 5
#define PCINT4 4
#define PCINT3 3
#define PCINT2 2
#define PCINT1 1
#define PCINT0 0
#define CLKPCE 7
#define CLKPS3 3
#define CLKPS2 2
#define CLKPS1 1
#define CLKPS0 0
#define SP15 15
#define SP14 14
#define SP13 13
#define SP12 12
#define SP11 11
#define SP10 10
#define SP9 9
#define SP8 8
#define SP7 7
#define SP6 6
#define SP5 5
#define SP4 4
#define SP3 3
#define SP2 2
#define SP1 1
#define SP0 0
#define URSEL1 7
#define UBRR111 3
#define UBRR110 2
#define UBRR19 1
#define UBRR18 0
#define URSEL1 7
#define UMSEL1 6
#define UPM11 5
#define UPM10 4
#define USBS1 3
#define UCSZ11 2
#define UCSZ10 1
#define UCPOL1 0
#define INT1 7
#define INT0 6
#define INT2 5
#define PCIE1 4
#define PCIE0 3
#define IVSEL 1
#define IVCE 0
#define INTF1 7
#define INTF0 6
#define INTF2 5
#define PCIF1 4
#define PCIF0 3
#define TOIE1 7
#define OCIE1A 6
#define OCIE1B 5
#define OCIE2 4
#define TICIE1 3
#define TOIE2 2
#define TOIE0 1
#define OCIE0 0
#define TOV1 7
#define OCF1A 6
#define OCF1B 5
#define OCF2 4
#define ICF1 3
#define TOV2 2
#define TOV0 1
#define OCF0 0
#define SPMIE 7
#define RWWSB 6
#define RWWSRE 4
#define BLBSET 3
#define PGWRT 2
#define PGERS 1
#define SPMEN 0
#define SM0 7
#define SRL2 6
#define SRL1 5
#define SRL0 4
#define SRW01 3
#define SRW00 2
#define SRW11 1
#define ISC2 0
#define SRE 7
#define SRW10 6
#define SE 5
#define SM1 4
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00 0
#define JTD 7
#define SM2 5
#define JTRF 4
#define WDRF 3
#define BORF 2
#define EXTRF 1
#define PORF 0
#define FOC0 7
#define WGM00 6
#define COM01 5
#define COM00 4
#define WGM01 3
#define CS02 2
#define CS01 1
#define CS00 0
#define TSM 7
#define XMBK 6
#define XMM2 5
#define XMM1 4
#define XMM0 3
#define PUD 2
#define PSR2 1
#define PSR310 0
#define COM1A1 7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A 3
#define FOC1B 2
#define WGM11 1
#define WGM10 0
#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12 2
#define CS11 1
#define CS10 0
#define FOC2 7
#define WGM20 6
#define COM21 5
#define COM20 4
#define WGM21 3
#define CS22 2
#define CS21 1
#define CS20 0
#define AS2 3
#define TCN2UB 2
#define TCON2UB 2
#define OCR2UB 1
#define TCR2UB 0
#define WDCE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#define URSEL0 7
#define UBRR011 3
#define UBRR010 2
#define UBRR09 1
#define UBRR08 0
#define URSEL0 7
#define UMSEL0 6
#define UPM01 5
#define UPM00 4
#define USBS0 3
#define UCSZ01 2
#define UCSZ00 1
#define UCPOL0 0
#define EEAR8 0
#define EERIE 3
#define EEMWE 2
#define EEWE 1
#define EERE 0
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
#define DDC7 7
#define DDC6 6
#define DDC5 5
#define DDC4 4
#define DDC3 3
#define DDC2 2
#define DDC1 1
#define DDC0 0
#define PINC7 7
#define PINC6 6
#define PINC5 5
#define PINC4 4
#define PINC3 3
#define PINC2 2
#define PINC1 1
#define PINC0 0
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
#define SPIF 7
#define WCOL 6
#define SPI2X 0
#define SPIE 7
#define SPE 6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
#define RXC0 7
#define TXC0 6
#define UDRE0 5
#define FE0 4
#define DOR0 3
#define UPE0 2
#define U2X0 1
#define MPCM0 0
#define RXCIE0 7
#define TXCIE0 6
#define UDRIE0 5
#define RXEN0 4
#define TXEN0 3
#define UCSZ02 2
#define RXB80 1
#define TXB80 0
#define ACD 7
#define ACBG 6
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIC 2
#define ACIS1 1
#define ACIS0 0
#define PE2 2
#define PE1 1
#define PE0 0
#define DDE2 2
#define DDE1 1
#define DDE0 0
#define PINE2 2
#define PINE1 1
#define PINE0 0
#define RXC1 7
#define TXC1 6
#define UDRE1 5
#define FE1 4
#define DOR1 3
#define UPE1 2
#define U2X1 1
#define MPCM1 0
#define RXCIE1 7
#define TXCIE1 6
#define UDRIE1 5
#define RXEN1 4
#define TXEN1 3
#define UCSZ12 2
#define RXB81 1
#define TXB81 0
#define SPM_PAGESIZE 128
#define RAMSTART 0x100
#define RAMEND 0x4FF
#define XRAMEND 0xFFFF
#define E2END 0x1FF
#define E2PAGESIZE 4
#define FLASHEND 0x3FFF
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
#define FUSE_BOOTRST (unsigned char)~_BV(0)
#define FUSE_BOOTSZ0 (unsigned char)~_BV(1)
#define FUSE_BOOTSZ1 (unsigned char)~_BV(2)
#define FUSE_EESAVE (unsigned char)~_BV(3)
#define FUSE_WDTON (unsigned char)~_BV(4)
#define FUSE_SPIEN (unsigned char)~_BV(5)
#define FUSE_JTAGEN (unsigned char)~_BV(6)
#define FUSE_OCDEN (unsigned char)~_BV(7)
#define HFUSE_DEFAULT (FUSE_BOOTSZ0 & FUSE_BOOTSZ1 & FUSE_SPIEN & FUSE_JTAGEN)
#define FUSE_BODLEVEL0 (unsigned char)~_BV(1)
#define FUSE_BODLEVEL1 (unsigned char)~_BV(2)
#define FUSE_BODLEVEL2 (unsigned char)~_BV(3)
#define FUSE_M161C (unsigned char)~_BV(4)
#define EFUSE_DEFAULT (0xFF)
#define __LOCK_BITS_EXIST
#define __BOOT_LOCK_BITS_0_EXIST
#define __BOOT_LOCK_BITS_1_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x94
#define SIGNATURE_2 0x04
#define SLEEP_MODE_IDLE 0
#define SLEEP_MODE_PWR_DOWN 1
#define SLEEP_MODE_PWR_SAVE 2
#define SLEEP_MODE_ADC 3
#define SLEEP_MODE_STANDBY 4
#define SLEEP_MODE_EXT_STANDBY 5
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)
#pragma GCC system_header
#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_INTERRUPT2
#pragma GCC poison SIG_PIN_CHANGE0
#pragma GCC poison SIG_PIN_CHANGE1
#pragma GCC poison SIG_INPUT_CAPTURE3
#pragma GCC poison SIG_OUTPUT_COMPARE3A
#pragma GCC poison SIG_OUTPUT_COMPARE3B
#pragma GCC poison SIG_OVERFLOW3
#pragma GCC poison SIG_OUTPUT_COMPARE2
#pragma GCC poison SIG_OVERFLOW2
#pragma GCC poison SIG_INPUT_CAPTURE1
#pragma GCC poison SIG_OUTPUT_COMPARE1A
#pragma GCC poison SIG_OUTPUT_COMPARE1B
#pragma GCC poison SIG_OVERFLOW1
#pragma GCC poison SIG_OUTPUT_COMPARE0
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_SPI
#pragma GCC poison SIG_USART0_RECV
#pragma GCC poison SIG_USART1_RECV
#pragma GCC poison SIG_USART0_DATA
#pragma GCC poison SIG_USART1_DATA
#pragma GCC poison SIG_USART0_TRANS
#pragma GCC poison SIG_USART1_TRANS
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_COMPARATOR
#pragma GCC poison SIG_SPM_READY
#endif
#endif
