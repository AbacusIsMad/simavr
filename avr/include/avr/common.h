#ifndef _AVR_COMMON_H
#define _AVR_COMMON_H
#include <avr/sfr_defs.h>
#if __AVR_ARCH__ >= 100
# ifndef SPL
# define SPL _SFR_MEM8(0x3D)
# endif
# ifndef SPH
# define SPH _SFR_MEM8(0x3E)
# endif
# ifndef SP
# define SP _SFR_MEM16(0x3D)
# endif
#elif __AVR_ARCH__ != 1
# ifndef SPL
# define SPL _SFR_IO8(0x3D)
# endif
# if XRAMEND < 0x100 && !defined(__COMPILING_AVR_LIBC__)
# ifndef SP
# define SP _SFR_IO8(0x3D)
# endif
# else
# ifndef SP
# define SP _SFR_IO16(0x3D)
# endif
# ifndef SPH
# define SPH _SFR_IO8(0x3E)
# endif
# endif
#endif
#ifndef SREG
# if __AVR_ARCH__ >= 100
# define SREG _SFR_MEM8(0x3F)
# else
# define SREG _SFR_IO8(0x3F)
# endif
#endif
#ifndef SREG_C
# define SREG_C (0)
#endif
#ifndef SREG_Z
# define SREG_Z (1)
#endif
#ifndef SREG_N
# define SREG_N (2)
#endif
#ifndef SREG_V
# define SREG_V (3)
#endif
#ifndef SREG_S
# define SREG_S (4)
#endif
#ifndef SREG_H
# define SREG_H (5)
#endif
#ifndef SREG_T
# define SREG_T (6)
#endif
#ifndef SREG_I
# define SREG_I (7)
#endif
#if defined(__COMPILING_AVR_LIBC__)
# if __AVR_ARCH__ == 6
# ifndef EIND
# define EIND _SFR_IO8(0X3C)
# endif
# elif __AVR_ARCH__ >= 100
# ifndef EIND
# define EIND _SFR_MEM8(0x3C)
# endif
# endif
# ifndef EECR
# define EECR _SFR_IO8(0x1C)
# endif
# ifndef EEDR
# define EEDR _SFR_IO8(0x1D)
# endif
# ifndef EEAR
# define EEAR _SFR_IO16(0x1E)
# endif
# ifndef EEARL
# define EEARL _SFR_IO8(0x1E)
# endif
# ifndef EEARH
# define EEARH _SFR_IO8(0x1F)
# endif
# ifndef EERE
# define EERE (0)
# endif
# ifndef EEWE
# define EEWE (1)
# endif
# ifndef EEMWE
# define EEMWE (2)
# endif
# ifndef EERIE
# define EERIE (3)
# endif
#ifndef RAMPZ
# if defined(__AVR_HAVE_RAMPZ__) && __AVR_HAVE_RAMPZ__
# if __AVR_ARCH__ >= 100
# define RAMPZ _SFR_MEM8(0x3B)
# else
# define RAMPZ _SFR_IO8(0x3B)
# endif
# endif
#endif
#endif
#if __AVR_ARCH__ != 1
# define XL r26
# define XH r27
# define YL r28
# define YH r29
#endif
#define ZL r30
#define ZH r31
#if defined(SREG)
# define AVR_STATUS_REG SREG
# if __AVR_ARCH__ >= 100
# define AVR_STATUS_ADDR _SFR_MEM_ADDR(SREG)
# else
# define AVR_STATUS_ADDR _SFR_IO_ADDR(SREG)
# endif
#endif
#if defined(SP)
# define AVR_STACK_POINTER_REG SP
# if __AVR_ARCH__ >= 100
# define AVR_STACK_POINTER_ADDR _SFR_MEM_ADDR(SP)
# else
# define AVR_STACK_POINTER_ADDR _SFR_IO_ADDR(SP)
# endif
#endif
#if defined(SPH)
# define _HAVE_AVR_STACK_POINTER_HI 1
# define AVR_STACK_POINTER_HI_REG SPH
# if __AVR_ARCH__ >= 100
# define AVR_STACK_POINTER_HI_ADDR _SFR_MEM_ADDR(SPH)
# else
# define AVR_STACK_POINTER_HI_ADDR _SFR_IO_ADDR(SPH)
# endif
#endif
#if defined(SPL)
# define AVR_STACK_POINTER_LO_REG SPL
# if __AVR_ARCH__ >= 100
# define AVR_STACK_POINTER_LO_ADDR _SFR_MEM_ADDR(SPL)
# else
# define AVR_STACK_POINTER_LO_ADDR _SFR_IO_ADDR(SPL)
# endif
#endif
#if defined(RAMPD)
# define AVR_RAMPD_REG RAMPD
# if __AVR_ARCH__ >= 100
# define AVR_RAMPD_ADDR _SFR_MEM_ADDR(RAMPD)
# else
# define AVR_RAMPD_ADDR _SFR_IO_ADDR(RAMPD)
# endif
#endif
#if defined(RAMPX)
# define AVR_RAMPX_REG RAMPX
# if __AVR_ARCH__ >= 100
# define AVR_RAMPX_ADDR _SFR_MEM_ADDR(RAMPX)
# else
# define AVR_RAMPX_ADDR _SFR_IO_ADDR(RAMPX)
# endif
#endif
#if defined(RAMPY)
# define AVR_RAMPY_REG RAMPY
# if __AVR_ARCH__ >= 100
# define AVR_RAMPY_ADDR _SFR_MEM_ADDR(RAMPY)
# else
# define AVR_RAMPY_ADDR _SFR_IO_ADDR(RAMPY)
# endif
#endif
#if defined(RAMPZ)
# define AVR_RAMPZ_REG RAMPZ
# if __AVR_ARCH__ >= 100
# define AVR_RAMPZ_ADDR _SFR_MEM_ADDR(RAMPZ)
# else
# define AVR_RAMPZ_ADDR _SFR_IO_ADDR(RAMPZ)
# endif
#endif
#if defined(EIND)
# define AVR_EXTENDED_INDIRECT_REG EIND
# if __AVR_ARCH__ >= 100
# define AVR_EXTENDED_INDIRECT_ADDR _SFR_MEM_ADDR(EIND)
# else
# define AVR_EXTENDED_INDIRECT_ADDR _SFR_IO_ADDR(EIND)
# endif
#endif
#ifndef __AVR_HAVE_MOVW__
# if defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
# define __AVR_HAVE_MOVW__ 1
# endif
#endif
#ifndef __AVR_HAVE_LPMX__
# if defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
# define __AVR_HAVE_LPMX__ 1
# endif
#endif
#ifndef __AVR_HAVE_MUL__
# if defined(__AVR_ENHANCED__) && __AVR_ENHANCED__
# define __AVR_HAVE_MUL__ 1
# endif
#endif
#endif
