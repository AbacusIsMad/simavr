#ifndef F_CPU
# error "setbaud.h requires F_CPU to be defined"
#endif
#ifndef BAUD
# error "setbaud.h requires BAUD to be defined"
#endif
#if !(F_CPU)
# error "F_CPU must be a constant value"
#endif
#if !(BAUD)
# error "BAUD must be a constant value"
#endif
#if defined(__DOXYGEN__)
#define BAUD_TOL 2
#define UBRR_VALUE
#define UBRRL_VALUE
#define UBRRH_VALUE
#define USE_2X 0
#else
#undef USE_2X
#ifndef BAUD_TOL
# define BAUD_TOL 2
#endif
#ifdef __ASSEMBLER__
#define UBRR_VALUE (((F_CPU) + 8 * (BAUD)) / (16 * (BAUD)) -1)
#else
#define UBRR_VALUE (((F_CPU) + 8UL * (BAUD)) / (16UL * (BAUD)) -1UL)
#endif
#if 100 * (F_CPU) > (16 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) + (BAUD) * (BAUD_TOL))
# define USE_2X 1
#elif 100 * (F_CPU) < (16 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) - (BAUD) * (BAUD_TOL))
# define USE_2X 1
#else
# define USE_2X 0
#endif
#if USE_2X
#undef UBRR_VALUE
#ifdef __ASSEMBLER__
#define UBRR_VALUE (((F_CPU) + 4 * (BAUD)) / (8 * (BAUD)) -1)
#else
#define UBRR_VALUE (((F_CPU) + 4UL * (BAUD)) / (8UL * (BAUD)) -1UL)
#endif
#if 100 * (F_CPU) > (8 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) + (BAUD) * (BAUD_TOL))
# warning "Baud rate achieved is higher than allowed"
#endif
#if 100 * (F_CPU) < (8 * ((UBRR_VALUE) + 1)) * (100 * (BAUD) - (BAUD) * (BAUD_TOL))
# warning "Baud rate achieved is lower than allowed"
#endif
#endif
#ifdef UBRR_VALUE
# if UBRR_VALUE >= (1 << 12)
# warning "UBRR value overflow"
# endif
# define UBRRL_VALUE (UBRR_VALUE & 0xff)
# define UBRRH_VALUE (UBRR_VALUE >> 8)
#endif
#endif
