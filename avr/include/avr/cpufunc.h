#ifndef _AVR_CPUFUNC_H_
#define _AVR_CPUFUNC_H_ 1
#include <stdint.h>
#if defined(__DOXYGEN__)
#define _NOP()
#else
#define _NOP() __asm__ __volatile__("nop")
#endif
#if defined(__DOXYGEN__)
#define _MemoryBarrier()
#else
#define _MemoryBarrier() __asm__ __volatile__("":::"memory")
#endif
void ccp_write_io (uint8_t *__ioaddr, uint8_t __value);
#endif
