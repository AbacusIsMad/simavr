#ifndef _UTIL_PARITY_H_
#define _UTIL_PARITY_H_
#define parity_even_bit(val) (__extension__({ unsigned char __t; __asm__ ( "mov __tmp_reg__,%0" "\n\t" "swap %0" "\n\t" "eor %0,__tmp_reg__" "\n\t" "mov __tmp_reg__,%0" "\n\t" "lsr %0" "\n\t" "lsr %0" "\n\t" "eor %0,__tmp_reg__" : "=r" (__t) : "0" ((unsigned char)(val)) : "r0" ); (((__t + 1) >> 1) & 1); }))
#endif
