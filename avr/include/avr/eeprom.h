#ifndef _AVR_EEPROM_H_
#define _AVR_EEPROM_H_ 1
#include <avr/io.h>
#if !E2END && !defined(__DOXYGEN__) && !defined(__COMPILING_AVR_LIBC__)
# warning "Device does not have EEPROM available."
#else
#if defined (EEAR) && !defined (EEARL) && !defined (EEARH)
#define EEARL EEAR
#endif
#if (EEPROM_PAGE_SIZE == 1)
#define __EEPROM_NON_PAGE_WRITE_AVAILABLE__ 1
#endif
#ifndef __ASSEMBLER__
#include <stddef.h>
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
#ifndef __ATTR_PURE__
# ifdef __DOXYGEN__
# define __ATTR_PURE__
# else
# define __ATTR_PURE__ __attribute__((__pure__))
# endif
#endif
#define EEMEM __attribute__((section(".eeprom")))
#if defined (__DOXYGEN__)
# define eeprom_is_ready()
#elif defined (NVM_STATUS)
# define eeprom_is_ready() bit_is_clear (NVM_STATUS, NVM_NVMBUSY_bp)
#elif defined (NVMCTRL_STATUS)
# define eeprom_is_ready() bit_is_clear (NVMCTRL_STATUS, NVMCTRL_EEBUSY_bp)
#elif defined (DEECR)
# define eeprom_is_ready() bit_is_clear (DEECR, BSY)
#elif defined (EEPE)
# define eeprom_is_ready() bit_is_clear (EECR, EEPE)
#else
# define eeprom_is_ready() bit_is_clear (EECR, EEWE)
#endif
#define eeprom_busy_wait() do {} while (!eeprom_is_ready())
uint8_t eeprom_read_byte (const uint8_t *__p) __ATTR_PURE__;
uint16_t eeprom_read_word (const uint16_t *__p) __ATTR_PURE__;
uint32_t eeprom_read_dword (const uint32_t *__p) __ATTR_PURE__;
float eeprom_read_float (const float *__p) __ATTR_PURE__;
void eeprom_read_block (void *__dst, const void *__src, size_t __n);
void eeprom_write_byte (uint8_t *__p, uint8_t __value);
void eeprom_write_word (uint16_t *__p, uint16_t __value);
void eeprom_write_dword (uint32_t *__p, uint32_t __value);
void eeprom_write_float (float *__p, float __value);
void eeprom_write_block (const void *__src, void *__dst, size_t __n);
void eeprom_update_byte (uint8_t *__p, uint8_t __value);
void eeprom_update_word (uint16_t *__p, uint16_t __value);
void eeprom_update_dword (uint32_t *__p, uint32_t __value);
void eeprom_update_float (float *__p, float __value);
void eeprom_update_block (const void *__src, void *__dst, size_t __n);
#define _EEPUT(addr, val) eeprom_write_byte ((uint8_t *)(addr), (uint8_t)(val))
#define __EEPUT(addr, val) eeprom_write_byte ((uint8_t *)(addr), (uint8_t)(val))
#define _EEGET(var, addr) (var) = eeprom_read_byte ((const uint8_t *)(addr))
#define __EEGET(var, addr) (var) = eeprom_read_byte ((const uint8_t *)(addr))
#ifdef __cplusplus
}
#endif
#endif
#endif
#endif
