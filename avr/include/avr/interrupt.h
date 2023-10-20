#ifndef _AVR_INTERRUPT_H_
#define _AVR_INTERRUPT_H_
#include <avr/io.h>
#if !defined(__DOXYGEN__) && !defined(__STRINGIFY)
#define __STRINGIFY(x) #x
#endif
#if defined(__DOXYGEN__)
#define sei()
#else
# define sei() __asm__ __volatile__ ("sei" ::: "memory")
#endif
#if defined(__DOXYGEN__)
#define cli()
#else
# define cli() __asm__ __volatile__ ("cli" ::: "memory")
#endif
#if defined(__DOXYGEN__)
# define ISR(vector, [attributes])
#else
#if (__GNUC__ == 4 && __GNUC_MINOR__ >= 1) || (__GNUC__ > 4)
# define __INTR_ATTRS used, externally_visible
#else
# define __INTR_ATTRS used
#endif
#ifdef __cplusplus
# define ISR(vector, ...) extern "C" void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; void vector (void)
#else
# define ISR(vector, ...) void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; void vector (void)
#endif
#endif
#if defined(__DOXYGEN__)
# define SIGNAL(vector)
#else
#ifdef __cplusplus
# define SIGNAL(vector) extern "C" void vector(void) __attribute__ ((signal, __INTR_ATTRS)); void vector (void)
#else
# define SIGNAL(vector) void vector (void) __attribute__ ((signal, __INTR_ATTRS)); void vector (void)
#endif
#endif
#if defined(__DOXYGEN__)
# define EMPTY_INTERRUPT(vector)
#else
#ifdef __cplusplus
# define EMPTY_INTERRUPT(vector) extern "C" void vector(void) __attribute__ ((signal,naked,__INTR_ATTRS)); void vector (void) { __asm__ __volatile__ ("reti" ::); }
#else
# define EMPTY_INTERRUPT(vector) void vector (void) __attribute__ ((signal,naked,__INTR_ATTRS)); void vector (void) { __asm__ __volatile__ ("reti" ::); }
#endif
#endif
#if defined(__DOXYGEN__)
# define ISR_ALIAS(vector, target_vector)
#else
#ifdef __cplusplus
# if defined(__AVR_MEGA__) && __AVR_MEGA__
# define ISR_ALIAS(vector, tgt) extern "C" void vector (void) __attribute__((signal, naked, __INTR_ATTRS)); void vector (void) { asm volatile ("jmp " __STRINGIFY(tgt) ::); }
# else
# define ISR_ALIAS(vector, tgt) extern "C" void vector (void) __attribute__((signal, naked, __INTR_ATTRS)); void vector (void) { asm volatile ("rjmp " __STRINGIFY(tgt) ::); }
# endif
#else
# if defined(__AVR_MEGA__) && __AVR_MEGA__
# define ISR_ALIAS(vector, tgt) void vector (void) __attribute__((signal, naked, __INTR_ATTRS)); void vector (void) { asm volatile ("jmp " __STRINGIFY(tgt) ::); }
# else
# define ISR_ALIAS(vector, tgt) void vector (void) __attribute__((signal, naked, __INTR_ATTRS)); void vector (void) { asm volatile ("rjmp " __STRINGIFY(tgt) ::); }
# endif
#endif
#endif
#if defined(__DOXYGEN__)
# define reti()
#else
# define reti() __asm__ __volatile__ ("reti" ::)
#endif
#if defined(__DOXYGEN__)
# define BADISR_vect
#else
# define BADISR_vect __vector_default
#endif
#if defined(__DOXYGEN__)
# define ISR_BLOCK
# define ISR_NOBLOCK
# define ISR_NAKED
# define ISR_ALIASOF(target_vector)
#else
# define ISR_BLOCK
# define ISR_NOBLOCK __attribute__((interrupt))
# define ISR_NAKED __attribute__((naked))
# define ISR_ALIASOF(v) __attribute__((alias(__STRINGIFY(v))))
#endif
#endif
