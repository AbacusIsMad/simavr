#ifndef _UTIL_CRC16_H_
#define _UTIL_CRC16_H_
#include <stdint.h>
static __inline__ uint16_t
_crc16_update(uint16_t __crc, uint8_t __data)
{
 uint8_t __tmp;
 uint16_t __ret;
 __asm__ __volatile__ (
  "eor %A0,%2" "\n\t"
  "mov %1,%A0" "\n\t"
  "swap %1" "\n\t"
  "eor %1,%A0" "\n\t"
  "mov __tmp_reg__,%1" "\n\t"
  "lsr %1" "\n\t"
  "lsr %1" "\n\t"
  "eor %1,__tmp_reg__" "\n\t"
  "mov __tmp_reg__,%1" "\n\t"
  "lsr %1" "\n\t"
  "eor %1,__tmp_reg__" "\n\t"
  "andi %1,0x07" "\n\t"
  "mov __tmp_reg__,%A0" "\n\t"
  "mov %A0,%B0" "\n\t"
  "lsr %1" "\n\t"
  "ror __tmp_reg__" "\n\t"
  "ror %1" "\n\t"
  "mov %B0,__tmp_reg__" "\n\t"
  "eor %A0,%1" "\n\t"
  "lsr __tmp_reg__" "\n\t"
  "ror %1" "\n\t"
  "eor %B0,__tmp_reg__" "\n\t"
  "eor %A0,%1"
  : "=r" (__ret), "=d" (__tmp)
  : "r" (__data), "0" (__crc)
  : "r0"
 );
 return __ret;
}
static __inline__ uint16_t
_crc_xmodem_update(uint16_t __crc, uint8_t __data)
{
    uint16_t __ret;
    uint8_t __tmp1;
    uint8_t __tmp2;
    __asm__ __volatile__ (
        "eor    %B0,%3" "\n\t"
        "mov    __tmp_reg__,%B0" "\n\t"
        "swap   __tmp_reg__" "\n\t"
        "mov    %1,__tmp_reg__" "\n\t"
        "andi   %1,0x0f" "\n\t"
        "eor    %1,%B0" "\n\t"
        "mov    %2,%B0" "\n\t"
        "eor    %2,__tmp_reg__" "\n\t"
        "lsl    %2" "\n\t"
        "andi   %2,0xe0" "\n\t"
        "eor    %1,%2" "\n\t"
        "mov    %2,__tmp_reg__" "\n\t"
        "eor    %2,%B0" "\n\t"
        "andi   %2,0xf0" "\n\t"
        "lsr    %2" "\n\t"
        "mov    __tmp_reg__,%B0" "\n\t"
        "lsl    __tmp_reg__" "\n\t"
        "rol    %2" "\n\t"
        "lsr    %B0" "\n\t"
        "lsr    %B0" "\n\t"
        "lsr    %B0" "\n\t"
        "andi   %B0,0x1f" "\n\t"
        "eor    %B0,%2" "\n\t"
        "eor    %B0,%A0" "\n\t"
        "mov    %A0,%1" "\n\t"
        : "=d" (__ret), "=d" (__tmp1), "=d" (__tmp2)
        : "r" (__data), "0" (__crc)
        : "r0"
    );
    return __ret;
}
static __inline__ uint16_t
_crc_ccitt_update (uint16_t __crc, uint8_t __data)
{
    uint16_t __ret;
    __asm__ __volatile__ (
        "eor    %A0,%1" "\n\t"
        "mov    __tmp_reg__,%A0" "\n\t"
        "swap   %A0" "\n\t"
        "andi   %A0,0xf0" "\n\t"
        "eor    %A0,__tmp_reg__" "\n\t"
        "mov    __tmp_reg__,%B0" "\n\t"
        "mov    %B0,%A0" "\n\t"
        "swap   %A0" "\n\t"
        "andi   %A0,0x0f" "\n\t"
        "eor    __tmp_reg__,%A0" "\n\t"
        "lsr    %A0" "\n\t"
        "eor    %B0,%A0" "\n\t"
        "eor    %A0,%B0" "\n\t"
        "lsl    %A0" "\n\t"
        "lsl    %A0" "\n\t"
        "lsl    %A0" "\n\t"
        "eor    %A0,__tmp_reg__"
        : "=d" (__ret)
        : "r" (__data), "0" (__crc)
        : "r0"
    );
    return __ret;
}
static __inline__ uint8_t
_crc_ibutton_update(uint8_t __crc, uint8_t __data)
{
 uint8_t __i, __pattern;
 __asm__ __volatile__ (
  "	eor	%0, %4" "\n\t"
  "	ldi	%1, 8" "\n\t"
  "	ldi	%2, 0x8C" "\n\t"
  "1:	lsr	%0" "\n\t"
  "	brcc	2f" "\n\t"
  "	eor	%0, %2" "\n\t"
  "2:	dec	%1" "\n\t"
  "	brne	1b" "\n\t"
  : "=r" (__crc), "=d" (__i), "=d" (__pattern)
  : "0" (__crc), "r" (__data));
 return __crc;
}
static __inline__ uint8_t
_crc8_ccitt_update(uint8_t __crc, uint8_t __data)
{
    uint8_t __i, __pattern;
    __asm__ __volatile__ (
        "    eor    %0, %4" "\n\t"
        "    ldi    %1, 8" "\n\t"
        "    ldi    %2, 0x07" "\n\t"
        "1:  lsl    %0" "\n\t"
        "    brcc   2f" "\n\t"
        "    eor    %0, %2" "\n\t"
        "2:  dec    %1" "\n\t"
        "    brne   1b" "\n\t"
        : "=r" (__crc), "=d" (__i), "=d" (__pattern)
        : "0" (__crc), "r" (__data));
    return __crc;
}
#endif
