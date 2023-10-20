#undef assert
#include <stdlib.h>
#if defined(__DOXYGEN__)
# define assert(expression)
#else
# if defined(NDEBUG)
# define assert(e) ((void)0)
# else
# if defined(__ASSERT_USE_STDERR)
# define assert(e) ((e) ? (void)0 : __assert(__func__, __FILE__, __LINE__, #e))
# else
# define assert(e) ((e) ? (void)0 : abort())
# endif
# endif
#endif
#if (defined __STDC_VERSION__ && __STDC_VERSION__ >= 201112L) || ((_GNUC_ > 4 || (_GNUC_ == 4 && _GNUC_MINOR_ >= 6)) && !defined __cplusplus)
# undef static_assert
# define static_assert _Static_assert
#endif
#ifdef __cplusplus
extern "C" {
#endif
#if !defined(__DOXYGEN__)
extern void __assert(const char *__func, const char *__file,
       int __lineno, const char *__sexp);
#endif
#ifdef __cplusplus
}
#endif
