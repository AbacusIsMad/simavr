#ifndef _UTIL_ATOMIC_H_
#define _UTIL_ATOMIC_H_ 1
#include <avr/io.h>
#include <avr/interrupt.h>
#if !defined(__DOXYGEN__)
static __inline__ uint8_t __iSeiRetVal(void)
{
    sei();
    return 1;
}
static __inline__ uint8_t __iCliRetVal(void)
{
    cli();
    return 1;
}
static __inline__ void __iSeiParam(const uint8_t *__s)
{
    sei();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}
static __inline__ void __iCliParam(const uint8_t *__s)
{
    cli();
    __asm__ volatile ("" ::: "memory");
    (void)__s;
}
static __inline__ void __iRestore(const uint8_t *__s)
{
    SREG = *__s;
    __asm__ volatile ("" ::: "memory");
}
#endif
#if defined(__DOXYGEN__)
#define ATOMIC_BLOCK(type)
#else
#define ATOMIC_BLOCK(type) for ( type, __ToDo = __iCliRetVal(); __ToDo ; __ToDo = 0 )
#endif
#if defined(__DOXYGEN__)
#define NONATOMIC_BLOCK(type)
#else
#define NONATOMIC_BLOCK(type) for ( type, __ToDo = __iSeiRetVal(); __ToDo ; __ToDo = 0 )
#endif
#if defined(__DOXYGEN__)
#define ATOMIC_RESTORESTATE
#else
#define ATOMIC_RESTORESTATE uint8_t sreg_save __attribute__((__cleanup__(__iRestore))) = SREG
#endif
#if defined(__DOXYGEN__)
#define ATOMIC_FORCEON
#else
#define ATOMIC_FORCEON uint8_t sreg_save __attribute__((__cleanup__(__iSeiParam))) = 0
#endif
#if defined(__DOXYGEN__)
#define NONATOMIC_RESTORESTATE
#else
#define NONATOMIC_RESTORESTATE uint8_t sreg_save __attribute__((__cleanup__(__iRestore))) = SREG
#endif
#if defined(__DOXYGEN__)
#define NONATOMIC_FORCEOFF
#else
#define NONATOMIC_FORCEOFF uint8_t sreg_save __attribute__((__cleanup__(__iCliParam))) = 0
#endif
#endif
