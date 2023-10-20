#ifndef _AVR_IOTN28_H_
#define _AVR_IOTN28_H_ 1
#ifndef _AVR_IO_H_
# error "Include <avr/io.h> instead of this file."
#endif
#ifndef _AVR_IOXXX_H_
# define _AVR_IOXXX_H_ "iotn28.h"
#else
# error "Attempt to include more than one <avr/ioXXX.h> file."
#endif
#ifndef __ASSEMBLER__
# warning "MCU not supported by the C compiler"
#endif
#define OSCCAL _SFR_IO8(0x00)
#define WDTCR _SFR_IO8(0x01)
#define MODCR _SFR_IO8(0x02)
#define TCNT0 _SFR_IO8(0x03)
#define TCCR0 _SFR_IO8(0x04)
#define IFR _SFR_IO8(0x05)
#define ICR _SFR_IO8(0x06)
#define MCUCS _SFR_IO8(0x07)
#define ACSR _SFR_IO8(0x08)
#define PIND _SFR_IO8(0x10)
#define DDRD _SFR_IO8(0x11)
#define PORTD _SFR_IO8(0x12)
#define PINB _SFR_IO8(0x16)
#define PINA _SFR_IO8(0x19)
#define PACR _SFR_IO8(0x1A)
#define PORTA _SFR_IO8(0x1B)
#define INT0_vect_num 1
#define INT0_vect _VECTOR(1)
#define SIG_INTERRUPT0 _VECTOR(1)
#define INT1_vect_num 2
#define INT1_vect _VECTOR(2)
#define SIG_INTERRUPT1 _VECTOR(2)
#define LOWLEVEL_IO_PINS_vect_num 3
#define LOWLEVEL_IO_PINS_vect _VECTOR(3)
#define SIG_PIN _VECTOR(3)
#define TIMER0_OVF_vect_num 4
#define TIMER0_OVF_vect _VECTOR(4)
#define SIG_OVERFLOW0 _VECTOR(4)
#define ANA_COMP_vect_num 5
#define ANA_COMP_vect _VECTOR(5)
#define SIG_COMPARATOR _VECTOR(5)
#define _VECTORS_SIZE 12
#define INT1 7
#define INT0 6
#define LLIE 5
#define TOIE0 4
#define ISC11 3
#define ISC10 2
#define ISC01 1
#define ISC00
#define INTF1 7
#define INTF0 6
#define TOV0 4
#define PLUPB 7
#define SE 5
#define SM 4
#define WDRF 3
#define EXTRF 1
#define PORF 0
#define FOV0 7
#define OOM01 4
#define OOM00 3
#define CS02 2
#define CS01 1
#define CS00 0
#define ONTIM4 7
#define ONTIM3 6
#define ONTIM2 5
#define ONTIM1 4
#define ONTIM0 3
#define MCONF2 2
#define MCONF1 1
#define MCONF0 0
#define WDTOE 4
#define WDE 3
#define WDP2 2
#define WDP1 1
#define WDP0 0
#define PA3 3
#define PA2 2
#define PA1 1
#define PA0 0
#define DDA3 3
#define PA2HC 2
#define DDA1 1
#define DDA0 0
#define PINA3 3
#define PINA1 1
#define PINA0 0
#define PINB7 7
#define PINB6 6
#define PINB5 5
#define PINB4 4
#define PINB3 3
#define PINB2 2
#define PINB1 1
#define PINB0 0
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
#define ACD 7
#define ACO 5
#define ACI 4
#define ACIE 3
#define ACIS1 1
#define ACIS0 0
#define RAMSTART 0x60
#define RAMEND 0x1F
#define XRAMEND 0x0
#define E2END 0x0
#define E2PAGESIZE 0
#define FLASHEND 0x7FF
#define FUSE_MEMORY_SIZE 1
#define FUSE_CKSEL0 (unsigned char)~_BV(0)
#define FUSE_CKSEL1 (unsigned char)~_BV(1)
#define FUSE_CKSEL2 (unsigned char)~_BV(2)
#define FUSE_CKSEL3 (unsigned char)~_BV(3)
#define FUSE_INTCAP (unsigned char)~_BV(4)
#define FUSE_DEFAULT (FUSE_CKSEL0 & FUSE_CKSEL2 & FUSE_CKSEL3)
#define __LOCK_BITS_EXIST
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x91
#define SIGNATURE_2 0x07
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)
#pragma GCC system_header
#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_PIN
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_COMPARATOR
#endif
#define SLEEP_MODE_IDLE (0x00<<4)
#define SLEEP_MODE_PWR_DOWN (0x01<<4)
#endif
