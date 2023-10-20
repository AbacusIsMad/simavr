#ifndef _AVR_BUILTINS_H_
#define _AVR_BUILTINS_H_
#ifndef __HAS_DELAY_CYCLES
#define __HAS_DELAY_CYCLES 1
#endif
extern void __builtin_avr_sei(void);
extern void __builtin_avr_cli(void);
extern void __builtin_avr_sleep(void);
extern void __builtin_avr_wdr(void);
extern unsigned char __builtin_avr_swap(unsigned char __b);
extern unsigned int __builtin_avr_fmul(unsigned char __a, unsigned char __b);
extern int __builtin_avr_fmuls(char __a, char __b);
extern int __builtin_avr_fmulsu(char __a, unsigned char __b);
#if __HAS_DELAY_CYCLES || defined(__DOXYGEN__)
extern void __builtin_avr_delay_cycles(unsigned long __n);
#endif
#endif
