#ifndef _AVR_SFR_DEFS_H_
#define _AVR_SFR_DEFS_H_ 1
#ifdef __ASSEMBLER__
#define _SFR_ASM_COMPAT 1
#elif !defined(_SFR_ASM_COMPAT)
#define _SFR_ASM_COMPAT 0
#endif
#ifndef __ASSEMBLER__
#include <inttypes.h>
#define _MMIO_BYTE(mem_addr) (*(volatile uint8_t *)(mem_addr))
#define _MMIO_WORD(mem_addr) (*(volatile uint16_t *)(mem_addr))
#define _MMIO_DWORD(mem_addr) (*(volatile uint32_t *)(mem_addr))
#endif
#if _SFR_ASM_COMPAT
#ifndef __SFR_OFFSET
# if __AVR_ARCH__ >= 100
# define __SFR_OFFSET 0x00
# else
# define __SFR_OFFSET 0x20
# endif
#endif
#if (__SFR_OFFSET != 0) && (__SFR_OFFSET != 0x20)
#error "__SFR_OFFSET must be 0 or 0x20"
#endif
#define _SFR_MEM8(mem_addr) (mem_addr)
#define _SFR_MEM16(mem_addr) (mem_addr)
#define _SFR_MEM32(mem_addr) (mem_addr)
#define _SFR_IO8(io_addr) ((io_addr) + __SFR_OFFSET)
#define _SFR_IO16(io_addr) ((io_addr) + __SFR_OFFSET)
#define _SFR_IO_ADDR(sfr) ((sfr) - __SFR_OFFSET)
#define _SFR_MEM_ADDR(sfr) (sfr)
#define _SFR_IO_REG_P(sfr) ((sfr) < 0x40 + __SFR_OFFSET)
#if (__SFR_OFFSET == 0x20)
#define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)
#elif !defined(__ASSEMBLER__)
#define _SFR_ADDR(sfr) (_SFR_IO_REG_P(sfr) ? (_SFR_IO_ADDR(sfr) + 0x20) : _SFR_MEM_ADDR(sfr))
#endif
#else
#ifndef __SFR_OFFSET
# if __AVR_ARCH__ >= 100
# define __SFR_OFFSET 0x00
# else
# define __SFR_OFFSET 0x20
# endif
#endif
#define _SFR_MEM8(mem_addr) _MMIO_BYTE(mem_addr)
#define _SFR_MEM16(mem_addr) _MMIO_WORD(mem_addr)
#define _SFR_MEM32(mem_addr) _MMIO_DWORD(mem_addr)
#define _SFR_IO8(io_addr) _MMIO_BYTE((io_addr) + __SFR_OFFSET)
#define _SFR_IO16(io_addr) _MMIO_WORD((io_addr) + __SFR_OFFSET)
#define _SFR_MEM_ADDR(sfr) ((uint16_t) &(sfr))
#define _SFR_IO_ADDR(sfr) (_SFR_MEM_ADDR(sfr) - __SFR_OFFSET)
#define _SFR_IO_REG_P(sfr) (_SFR_MEM_ADDR(sfr) < 0x40 + __SFR_OFFSET)
#define _SFR_ADDR(sfr) _SFR_MEM_ADDR(sfr)
#endif
#define _SFR_BYTE(sfr) _MMIO_BYTE(_SFR_ADDR(sfr))
#define _SFR_WORD(sfr) _MMIO_WORD(_SFR_ADDR(sfr))
#define _SFR_DWORD(sfr) _MMIO_DWORD(_SFR_ADDR(sfr))
#define _BV(bit) (1 << (bit))
#ifndef _VECTOR
#define _VECTOR(N) __vector_ ## N
#endif
#ifndef __ASSEMBLER__
#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit))
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define loop_until_bit_is_set(sfr, bit) do { } while (bit_is_clear(sfr, bit))
#define loop_until_bit_is_clear(sfr, bit) do { } while (bit_is_set(sfr, bit))
#endif
#endif
