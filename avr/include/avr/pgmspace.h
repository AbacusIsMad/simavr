#ifndef __PGMSPACE_H_
#define __PGMSPACE_H_ 1
#ifndef __DOXYGEN__
#define __need_size_t
#endif
#include <inttypes.h>
#include <stddef.h>
#include <avr/io.h>
#ifndef __DOXYGEN__
#ifndef __ATTR_CONST__
#define __ATTR_CONST__ __attribute__((__const__))
#endif
#ifndef __ATTR_PROGMEM__
#define __ATTR_PROGMEM__ __attribute__((__progmem__))
#endif
#ifndef __ATTR_PURE__
#define __ATTR_PURE__ __attribute__((__pure__))
#endif
#endif
#define PROGMEM __ATTR_PROGMEM__
#ifdef __cplusplus
extern "C" {
#endif
#if defined(__DOXYGEN__)
typedef void PROGMEM prog_void;
typedef char PROGMEM prog_char;
typedef unsigned char PROGMEM prog_uchar;
typedef int8_t PROGMEM prog_int8_t;
typedef uint8_t PROGMEM prog_uint8_t;
typedef int16_t PROGMEM prog_int16_t;
typedef uint16_t PROGMEM prog_uint16_t;
typedef int32_t PROGMEM prog_int32_t;
typedef uint32_t PROGMEM prog_uint32_t;
typedef int64_t PROGMEM prog_int64_t;
typedef uint64_t PROGMEM prog_uint64_t;
#ifndef PGM_P
#define PGM_P const char *
#endif
#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif
#elif defined(__PROG_TYPES_COMPAT__)
typedef void prog_void __attribute__((__progmem__,deprecated("prog_void type is deprecated.")));
typedef char prog_char __attribute__((__progmem__,deprecated("prog_char type is deprecated.")));
typedef unsigned char prog_uchar __attribute__((__progmem__,deprecated("prog_uchar type is deprecated.")));
typedef int8_t prog_int8_t __attribute__((__progmem__,deprecated("prog_int8_t type is deprecated.")));
typedef uint8_t prog_uint8_t __attribute__((__progmem__,deprecated("prog_uint8_t type is deprecated.")));
typedef int16_t prog_int16_t __attribute__((__progmem__,deprecated("prog_int16_t type is deprecated.")));
typedef uint16_t prog_uint16_t __attribute__((__progmem__,deprecated("prog_uint16_t type is deprecated.")));
typedef int32_t prog_int32_t __attribute__((__progmem__,deprecated("prog_int32_t type is deprecated.")));
typedef uint32_t prog_uint32_t __attribute__((__progmem__,deprecated("prog_uint32_t type is deprecated.")));
#if !__USING_MINT8
typedef int64_t prog_int64_t __attribute__((__progmem__,deprecated("prog_int64_t type is deprecated.")));
typedef uint64_t prog_uint64_t __attribute__((__progmem__,deprecated("prog_uint64_t type is deprecated.")));
#endif
#ifndef PGM_P
#define PGM_P const prog_char *
#endif
#ifndef PGM_VOID_P
#define PGM_VOID_P const prog_void *
#endif
#else
#ifndef PGM_P
#define PGM_P const char *
#endif
#ifndef PGM_VOID_P
#define PGM_VOID_P const void *
#endif
#endif
#if defined(__DOXYGEN__)
# define PSTR(s) ((const PROGMEM char *)(s))
#else
# define PSTR(s) (__extension__({static const char __c[] PROGMEM = (s); &__c[0];}))
#endif
#ifndef __DOXYGEN__
#define __LPM_classic__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint8_t __result; __asm__ __volatile__ ( "lpm" "\n\t" "mov %0, r0" "\n\t" : "=r" (__result) : "z" (__addr16) : "r0" ); __result; }))
#define __LPM_tiny__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; uint8_t __result; __asm__ ( "ld %0, z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; }))
#define __LPM_enhanced__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint8_t __result; __asm__ __volatile__ ( "lpm %0, Z" "\n\t" : "=r" (__result) : "z" (__addr16) ); __result; }))
#define __LPM_word_classic__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint16_t __result; __asm__ __volatile__ ( "lpm" "\n\t" "mov %A0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %B0, r0" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) : "r0" ); __result; }))
#define __LPM_word_tiny__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; uint16_t __result; __asm__ ( "ld %A0, z+" "\n\t" "ld %B0, z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#define __LPM_word_enhanced__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint16_t __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#define __LPM_dword_classic__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint32_t __result; __asm__ __volatile__ ( "lpm" "\n\t" "mov %A0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %B0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %C0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %D0, r0" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) : "r0" ); __result; }))
#define __LPM_dword_tiny__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; uint32_t __result; __asm__ ( "ld %A0, z+" "\n\t" "ld %B0, z+" "\n\t" "ld %C0, z+" "\n\t" "ld %D0, z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#define __LPM_dword_enhanced__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); uint32_t __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z+" "\n\t" "lpm %C0, Z+" "\n\t" "lpm %D0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#define __LPM_float_classic__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); float __result; __asm__ __volatile__ ( "lpm" "\n\t" "mov %A0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %B0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %C0, r0" "\n\t" "adiw r30, 1" "\n\t" "lpm" "\n\t" "mov %D0, r0" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) : "r0" ); __result; }))
#define __LPM_float_tiny__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr) + __AVR_TINY_PM_BASE_ADDRESS__; float __result; __asm__ ( "ld %A0, z+" "\n\t" "ld %B0, z+" "\n\t" "ld %C0, z+" "\n\t" "ld %D0, z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#define __LPM_float_enhanced__(addr) (__extension__({ uint16_t __addr16 = (uint16_t)(addr); float __result; __asm__ __volatile__ ( "lpm %A0, Z+" "\n\t" "lpm %B0, Z+" "\n\t" "lpm %C0, Z+" "\n\t" "lpm %D0, Z" "\n\t" : "=r" (__result), "=z" (__addr16) : "1" (__addr16) ); __result; }))
#if defined (__AVR_HAVE_LPMX__)
#define __LPM(addr) __LPM_enhanced__(addr)
#define __LPM_word(addr) __LPM_word_enhanced__(addr)
#define __LPM_dword(addr) __LPM_dword_enhanced__(addr)
#define __LPM_float(addr) __LPM_float_enhanced__(addr)
#elif defined (__AVR_TINY__)
#define __LPM(addr) __LPM_tiny__(addr)
#define __LPM_word(addr) __LPM_word_tiny__(addr)
#define __LPM_dword(addr) __LPM_dword_tiny__(addr)
#define __LPM_float(addr) __LPM_float_tiny__(addr)
#else
#define __LPM(addr) __LPM_classic__(addr)
#define __LPM_word(addr) __LPM_word_classic__(addr)
#define __LPM_dword(addr) __LPM_dword_classic__(addr)
#define __LPM_float(addr) __LPM_float_classic__(addr)
#endif
#endif
#define pgm_read_byte_near(address_short) __LPM((uint16_t)(address_short))
#define pgm_read_word_near(address_short) __LPM_word((uint16_t)(address_short))
#define pgm_read_dword_near(address_short) __LPM_dword((uint16_t)(address_short))
#define pgm_read_float_near(address_short) __LPM_float((uint16_t)(address_short))
#define pgm_read_ptr_near(address_short) (void*)__LPM_word((uint16_t)(address_short))
#if defined(RAMPZ) || defined(__DOXYGEN__)
#ifndef __DOXYGEN__
#define __ELPM_classic__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint8_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "mov r31, %B1" "\n\t" "mov r30, %A1" "\n\t" "elpm" "\n\t" "mov %0, r0" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r0", "r30", "r31" ); __result; }))
#define __ELPM_enhanced__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint8_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %0, Z+" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_xmega__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint8_t __result; __asm__ __volatile__ ( "in __tmp_reg__, %2" "\n\t" "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %0, Z+" "\n\t" "out %2, __tmp_reg__" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_word_classic__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint16_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "mov r31, %B1" "\n\t" "mov r30, %A1" "\n\t" "elpm" "\n\t" "mov %A0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %B0, r0" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r0", "r30", "r31" ); __result; }))
#define __ELPM_word_enhanced__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint16_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_word_xmega__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint16_t __result; __asm__ __volatile__ ( "in __tmp_reg__, %2" "\n\t" "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z" "\n\t" "out %2, __tmp_reg__" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_dword_classic__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint32_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "mov r31, %B1" "\n\t" "mov r30, %A1" "\n\t" "elpm" "\n\t" "mov %A0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %B0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %C0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %D0, r0" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r0", "r30", "r31" ); __result; }))
#define __ELPM_dword_enhanced__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint32_t __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z+" "\n\t" "elpm %C0, Z+" "\n\t" "elpm %D0, Z" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_dword_xmega__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); uint32_t __result; __asm__ __volatile__ ( "in __tmp_reg__, %2" "\n\t" "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z+" "\n\t" "elpm %C0, Z+" "\n\t" "elpm %D0, Z" "\n\t" "out %2, __tmp_reg__" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_float_classic__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); float __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "mov r31, %B1" "\n\t" "mov r30, %A1" "\n\t" "elpm" "\n\t" "mov %A0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %B0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %C0, r0" "\n\t" "in r0, %2" "\n\t" "adiw r30, 1" "\n\t" "adc r0, __zero_reg__" "\n\t" "out %2, r0" "\n\t" "elpm" "\n\t" "mov %D0, r0" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r0", "r30", "r31" ); __result; }))
#define __ELPM_float_enhanced__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); float __result; __asm__ __volatile__ ( "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z+" "\n\t" "elpm %C0, Z+" "\n\t" "elpm %D0, Z" "\n\t" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#define __ELPM_float_xmega__(addr) (__extension__({ uint32_t __addr32 = (uint32_t)(addr); float __result; __asm__ __volatile__ ( "in __tmp_reg__, %2" "\n\t" "out %2, %C1" "\n\t" "movw r30, %1" "\n\t" "elpm %A0, Z+" "\n\t" "elpm %B0, Z+" "\n\t" "elpm %C0, Z+" "\n\t" "elpm %D0, Z" "\n\t" "out %2, __tmp_reg__" : "=r" (__result) : "r" (__addr32), "I" (_SFR_IO_ADDR(RAMPZ)) : "r30", "r31" ); __result; }))
#if defined (__AVR_HAVE_RAMPD__)
#define __ELPM(addr) __ELPM_xmega__(addr)
#define __ELPM_word(addr) __ELPM_word_xmega__(addr)
#define __ELPM_dword(addr) __ELPM_dword_xmega__(addr)
#define __ELPM_float(addr) __ELPM_float_xmega__(addr)
#else
#if defined (__AVR_HAVE_LPMX__)
#define __ELPM(addr) __ELPM_enhanced__(addr)
#define __ELPM_word(addr) __ELPM_word_enhanced__(addr)
#define __ELPM_dword(addr) __ELPM_dword_enhanced__(addr)
#define __ELPM_float(addr) __ELPM_float_enhanced__(addr)
#else
#define __ELPM(addr) __ELPM_classic__(addr)
#define __ELPM_word(addr) __ELPM_word_classic__(addr)
#define __ELPM_dword(addr) __ELPM_dword_classic__(addr)
#define __ELPM_float(addr) __ELPM_float_classic__(addr)
#endif
#endif
#endif
#define pgm_read_byte_far(address_long) __ELPM((uint32_t)(address_long))
#define pgm_read_word_far(address_long) __ELPM_word((uint32_t)(address_long))
#define pgm_read_dword_far(address_long) __ELPM_dword((uint32_t)(address_long))
#define pgm_read_float_far(address_long) __ELPM_float((uint32_t)(address_long))
#define pgm_read_ptr_far(address_long) (void*)__ELPM_word((uint32_t)(address_long))
#endif
#define pgm_read_byte(address_short) pgm_read_byte_near(address_short)
#define pgm_read_word(address_short) pgm_read_word_near(address_short)
#define pgm_read_dword(address_short) pgm_read_dword_near(address_short)
#define pgm_read_float(address_short) pgm_read_float_near(address_short)
#define pgm_read_ptr(address_short) pgm_read_ptr_near(address_short)
#define pgm_get_far_address(var) ({ uint_farptr_t tmp; __asm__ __volatile__( "ldi	%A0, lo8(%1)" "\n\t" "ldi	%B0, hi8(%1)" "\n\t" "ldi	%C0, hh8(%1)" "\n\t" "clr	%D0" "\n\t" : "=d" (tmp) : "p" (&(var)) ); tmp; })
extern const void * memchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;
extern int memcmp_P(const void *, const void *, size_t) __ATTR_PURE__;
extern void *memccpy_P(void *, const void *, int __val, size_t);
extern void *memcpy_P(void *, const void *, size_t);
extern void *memmem_P(const void *, size_t, const void *, size_t) __ATTR_PURE__;
extern const void * memrchr_P(const void *, int __val, size_t __len) __ATTR_CONST__;
extern char *strcat_P(char *, const char *);
extern const char * strchr_P(const char *, int __val) __ATTR_CONST__;
extern const char * strchrnul_P(const char *, int __val) __ATTR_CONST__;
extern int strcmp_P(const char *, const char *) __ATTR_PURE__;
extern char *strcpy_P(char *, const char *);
extern int strcasecmp_P(const char *, const char *) __ATTR_PURE__;
extern char *strcasestr_P(const char *, const char *) __ATTR_PURE__;
extern size_t strcspn_P(const char *__s, const char * __reject) __ATTR_PURE__;
extern size_t strlcat_P (char *, const char *, size_t );
extern size_t strlcpy_P (char *, const char *, size_t );
extern size_t strnlen_P(const char *, size_t) __ATTR_CONST__;
extern int strncmp_P(const char *, const char *, size_t) __ATTR_PURE__;
extern int strncasecmp_P(const char *, const char *, size_t) __ATTR_PURE__;
extern char *strncat_P(char *, const char *, size_t);
extern char *strncpy_P(char *, const char *, size_t);
extern char *strpbrk_P(const char *__s, const char * __accept) __ATTR_PURE__;
extern const char * strrchr_P(const char *, int __val) __ATTR_CONST__;
extern char *strsep_P(char **__sp, const char * __delim);
extern size_t strspn_P(const char *__s, const char * __accept) __ATTR_PURE__;
extern char *strstr_P(const char *, const char *) __ATTR_PURE__;
extern char *strtok_P(char *__s, const char * __delim);
extern char *strtok_rP(char *__s, const char * __delim, char **__last);
extern size_t strlen_PF(uint_farptr_t src) __ATTR_CONST__;
extern size_t strnlen_PF(uint_farptr_t src, size_t len) __ATTR_CONST__;
extern void *memcpy_PF(void *dest, uint_farptr_t src, size_t len);
extern char *strcpy_PF(char *dest, uint_farptr_t src);
extern char *strncpy_PF(char *dest, uint_farptr_t src, size_t len);
extern char *strcat_PF(char *dest, uint_farptr_t src);
extern size_t strlcat_PF(char *dst, uint_farptr_t src, size_t siz);
extern char *strncat_PF(char *dest, uint_farptr_t src, size_t len);
extern int strcmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;
extern int strncmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;
extern int strcasecmp_PF(const char *s1, uint_farptr_t s2) __ATTR_PURE__;
extern int strncasecmp_PF(const char *s1, uint_farptr_t s2, size_t n) __ATTR_PURE__;
extern char *strstr_PF(const char *s1, uint_farptr_t s2);
extern size_t strlcpy_PF(char *dst, uint_farptr_t src, size_t siz);
extern int memcmp_PF(const void *, uint_farptr_t, size_t) __ATTR_PURE__;
#ifdef __DOXYGEN__
static inline size_t strlen_P(const char * s);
#else
extern size_t __strlen_P(const char *) __ATTR_CONST__;
__attribute__((__always_inline__)) static __inline__ size_t strlen_P(const char * s);
static __inline__ size_t strlen_P(const char *s) {
  return __builtin_constant_p(__builtin_strlen(s))
     ? __builtin_strlen(s) : __strlen_P(s);
}
#endif
#ifdef __cplusplus
}
#endif
#endif
