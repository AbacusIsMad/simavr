#ifndef _STDLIB_H_
#define _STDLIB_H_ 1
#ifndef __ASSEMBLER__
#ifndef __DOXYGEN__
#define __need_NULL
#define __need_size_t
#define __need_wchar_t
#include <stddef.h>
#ifndef __ptr_t
#define __ptr_t void *
#endif
#endif
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
 int quot;
 int rem;
} div_t;
typedef struct {
 long quot;
 long rem;
} ldiv_t;
typedef int (*__compar_fn_t)(const void *, const void *);
#ifndef __DOXYGEN__
#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif
#ifndef __ATTR_MALLOC__
# define __ATTR_MALLOC__ __attribute__((__malloc__))
#endif
#ifndef __ATTR_NORETURN__
# define __ATTR_NORETURN__ __attribute__((__noreturn__))
#endif
#ifndef __ATTR_PURE__
# define __ATTR_PURE__ __attribute__((__pure__))
#endif
#ifndef __ATTR_GNU_INLINE__
# ifdef __GNUC_STDC_INLINE__
# define __ATTR_GNU_INLINE__ __attribute__((__gnu_inline__))
# else
# define __ATTR_GNU_INLINE__
# endif
#endif
#endif
extern void abort(void) __ATTR_NORETURN__;
extern int abs(int __i) __ATTR_CONST__;
#ifndef __DOXYGEN__
#define abs(__i) __builtin_abs(__i)
#endif
extern long labs(long __i) __ATTR_CONST__;
#ifndef __DOXYGEN__
#define labs(__i) __builtin_labs(__i)
#endif
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb,
       size_t __size, int (*__compar)(const void *, const void *));
extern div_t div(int __num, int __denom) __asm__("__divmodhi4") __ATTR_CONST__;
extern ldiv_t ldiv(long __num, long __denom) __asm__("__divmodsi4") __ATTR_CONST__;
extern void qsort(void *__base, size_t __nmemb, size_t __size,
    __compar_fn_t __compar);
extern long strtol(const char *__nptr, char **__endptr, int __base);
extern unsigned long strtoul(const char *__nptr, char **__endptr, int __base);
extern long atol(const char *__s) __ATTR_PURE__;
extern int atoi(const char *__s) __ATTR_PURE__;
extern void exit(int __status) __ATTR_NORETURN__;
extern void *malloc(size_t __size) __ATTR_MALLOC__;
extern void free(void *__ptr);
extern size_t __malloc_margin;
extern char *__malloc_heap_start;
extern char *__malloc_heap_end;
extern void *calloc(size_t __nele, size_t __size) __ATTR_MALLOC__;
extern void *realloc(void *__ptr, size_t __size) __ATTR_MALLOC__;
extern double strtod(const char *__nptr, char **__endptr);
extern double atof(const char *__nptr);
#define RAND_MAX 0x7FFF
extern int rand(void);
extern void srand(unsigned int __seed);
extern int rand_r(unsigned long *__ctx);
#ifdef __DOXYGEN__
extern char *itoa(int val, char *s, int radix);
#else
extern __inline__ __ATTR_GNU_INLINE__
char *itoa (int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__itoa (int, char *, int);
 return __itoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__itoa_ncheck (int, char *, unsigned char);
 return __itoa_ncheck (__val, __s, __radix);
    }
}
#endif
#ifdef __DOXYGEN__
extern char *ltoa(long val, char *s, int radix);
#else
extern __inline__ __ATTR_GNU_INLINE__
char *ltoa (long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ltoa (long, char *, int);
 return __ltoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ltoa_ncheck (long, char *, unsigned char);
 return __ltoa_ncheck (__val, __s, __radix);
    }
}
#endif
#ifdef __DOXYGEN__
extern char *utoa(unsigned int val, char *s, int radix);
#else
extern __inline__ __ATTR_GNU_INLINE__
char *utoa (unsigned int __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__utoa (unsigned int, char *, int);
 return __utoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__utoa_ncheck (unsigned int, char *, unsigned char);
 return __utoa_ncheck (__val, __s, __radix);
    }
}
#endif
#ifdef __DOXYGEN__
extern char *ultoa(unsigned long val, char *s, int radix);
#else
extern __inline__ __ATTR_GNU_INLINE__
char *ultoa (unsigned long __val, char *__s, int __radix)
{
    if (!__builtin_constant_p (__radix)) {
 extern char *__ultoa (unsigned long, char *, int);
 return __ultoa (__val, __s, __radix);
    } else if (__radix < 2 || __radix > 36) {
 *__s = 0;
 return __s;
    } else {
 extern char *__ultoa_ncheck (unsigned long, char *, unsigned char);
 return __ultoa_ncheck (__val, __s, __radix);
    }
}
#endif
#define RANDOM_MAX 0x7FFFFFFF
extern long random(void);
extern void srandom(unsigned long __seed);
extern long random_r(unsigned long *__ctx);
#endif
#define DTOSTR_ALWAYS_SIGN 0x01
#define DTOSTR_PLUS_SIGN 0x02
#define DTOSTR_UPPERCASE 0x04
#ifndef __ASSEMBLER__
extern char *dtostre(double __val, char *__s, unsigned char __prec,
       unsigned char __flags);
extern char *dtostrf(double __val, signed char __width,
                     unsigned char __prec, char *__s);
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#ifndef __DOXYGEN__
extern int atexit(void (*)(void));
extern int system (const char *);
extern char *getenv (const char *);
#endif
#ifdef __cplusplus
}
#endif
#endif
#endif
