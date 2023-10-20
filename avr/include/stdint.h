#ifndef __STDINT_H_
#define __STDINT_H_
#ifndef __DOXYGEN__
#if __INT_MAX__ == 127
# define __USING_MINT8 1
#else
# define __USING_MINT8 0
#endif
#endif
#if defined(__DOXYGEN__)
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed int int16_t;
typedef unsigned int uint16_t;
typedef signed long int int32_t;
typedef unsigned long int uint32_t;
typedef signed long long int int64_t;
typedef unsigned long long int uint64_t;
#else
typedef signed int int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int uint8_t __attribute__((__mode__(__QI__)));
typedef signed int int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef signed int int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));
#if !__USING_MINT8
typedef signed int int64_t __attribute__((__mode__(__DI__)));
typedef unsigned int uint64_t __attribute__((__mode__(__DI__)));
#endif
#endif
typedef int16_t intptr_t;
typedef uint16_t uintptr_t;
typedef int8_t int_least8_t;
typedef uint8_t uint_least8_t;
typedef int16_t int_least16_t;
typedef uint16_t uint_least16_t;
typedef int32_t int_least32_t;
typedef uint32_t uint_least32_t;
#if !__USING_MINT8 || defined(__DOXYGEN__)
typedef int64_t int_least64_t;
typedef uint64_t uint_least64_t;
#endif
typedef int8_t int_fast8_t;
typedef uint8_t uint_fast8_t;
typedef int16_t int_fast16_t;
typedef uint16_t uint_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast32_t;
#if !__USING_MINT8 || defined(__DOXYGEN__)
typedef int64_t int_fast64_t;
typedef uint64_t uint_fast64_t;
#endif
#if __USING_MINT8
typedef int32_t intmax_t;
typedef uint32_t uintmax_t;
#else
typedef int64_t intmax_t;
typedef uint64_t uintmax_t;
#endif
#ifndef __DOXYGEN__
#ifndef __CONCAT
#define __CONCATenate(left, right) left ## right
#define __CONCAT(left, right) __CONCATenate(left, right)
#endif
#endif
#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)
#define INT8_MAX 0x7f
#define INT8_MIN (-INT8_MAX - 1)
#if __USING_MINT8
#define UINT8_MAX (__CONCAT(INT8_MAX, U) * 2U + 1U)
#define INT16_MAX 0x7fffL
#define INT16_MIN (-INT16_MAX - 1L)
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2UL + 1UL)
#define INT32_MAX 0x7fffffffLL
#define INT32_MIN (-INT32_MAX - 1LL)
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2ULL + 1ULL)
#else
#define UINT8_MAX (INT8_MAX * 2 + 1)
#define INT16_MAX 0x7fff
#define INT16_MIN (-INT16_MAX - 1)
#define UINT16_MAX (__CONCAT(INT16_MAX, U) * 2U + 1U)
#define INT32_MAX 0x7fffffffL
#define INT32_MIN (-INT32_MAX - 1L)
#define UINT32_MAX (__CONCAT(INT32_MAX, U) * 2UL + 1UL)
#endif
#define INT64_MAX 0x7fffffffffffffffLL
#define INT64_MIN (-INT64_MAX - 1LL)
#define UINT64_MAX (__CONCAT(INT64_MAX, U) * 2ULL + 1ULL)
#define INT_LEAST8_MAX INT8_MAX
#define INT_LEAST8_MIN INT8_MIN
#define UINT_LEAST8_MAX UINT8_MAX
#define INT_LEAST16_MAX INT16_MAX
#define INT_LEAST16_MIN INT16_MIN
#define UINT_LEAST16_MAX UINT16_MAX
#define INT_LEAST32_MAX INT32_MAX
#define INT_LEAST32_MIN INT32_MIN
#define UINT_LEAST32_MAX UINT32_MAX
#define INT_LEAST64_MAX INT64_MAX
#define INT_LEAST64_MIN INT64_MIN
#define UINT_LEAST64_MAX UINT64_MAX
#define INT_FAST8_MAX INT8_MAX
#define INT_FAST8_MIN INT8_MIN
#define UINT_FAST8_MAX UINT8_MAX
#define INT_FAST16_MAX INT16_MAX
#define INT_FAST16_MIN INT16_MIN
#define UINT_FAST16_MAX UINT16_MAX
#define INT_FAST32_MAX INT32_MAX
#define INT_FAST32_MIN INT32_MIN
#define UINT_FAST32_MAX UINT32_MAX
#define INT_FAST64_MAX INT64_MAX
#define INT_FAST64_MIN INT64_MIN
#define UINT_FAST64_MAX UINT64_MAX
#define INTPTR_MAX INT16_MAX
#define INTPTR_MIN INT16_MIN
#define UINTPTR_MAX UINT16_MAX
#define INTMAX_MAX INT64_MAX
#define INTMAX_MIN INT64_MIN
#define UINTMAX_MAX UINT64_MAX
#define PTRDIFF_MAX INT16_MAX
#define PTRDIFF_MIN INT16_MIN
#define SIG_ATOMIC_MAX INT8_MAX
#define SIG_ATOMIC_MIN INT8_MIN
#define SIZE_MAX UINT16_MAX
#ifndef WCHAR_MAX
#define WCHAR_MAX __WCHAR_MAX__
#define WCHAR_MIN __WCHAR_MIN__
#endif
#ifndef WINT_MAX
#define WINT_MAX __WINT_MAX__
#define WINT_MIN __WINT_MIN__
#endif
#endif
#if (!defined __cplusplus || __cplusplus >= 201103L || defined __STDC_CONSTANT_MACROS)
#ifdef __INT8_C
#define INT8_C(c) __INT8_C(c)
#define INT16_C(c) __INT16_C(c)
#define INT32_C(c) __INT32_C(c)
#define INT64_C(c) __INT64_C(c)
#define UINT8_C(c) __UINT8_C(c)
#define UINT16_C(c) __UINT16_C(c)
#define UINT32_C(c) __UINT32_C(c)
#define UINT64_C(c) __UINT64_C(c)
#define INTMAX_C(c) __INTMAX_C(c)
#define UINTMAX_C(c) __UINTMAX_C(c)
#else
#define INT8_C(value) ((int8_t) value)
#define UINT8_C(value) ((uint8_t) __CONCAT(value, U))
#if __USING_MINT8
#define INT16_C(value) __CONCAT(value, L)
#define UINT16_C(value) __CONCAT(value, UL)
#define INT32_C(value) ((int32_t) __CONCAT(value, LL))
#define UINT32_C(value) ((uint32_t) __CONCAT(value, ULL))
#else
#define INT16_C(value) value
#define UINT16_C(value) __CONCAT(value, U)
#define INT32_C(value) __CONCAT(value, L)
#define UINT32_C(value) __CONCAT(value, UL)
#endif
#define INT64_C(value) __CONCAT(value, LL)
#define UINT64_C(value) __CONCAT(value, ULL)
#define INTMAX_C(value) __CONCAT(value, LL)
#define UINTMAX_C(value) __CONCAT(value, ULL)
#endif
#endif
#endif
