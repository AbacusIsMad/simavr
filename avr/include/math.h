#ifndef __MATH_H
#define __MATH_H
#define M_E 2.7182818284590452354
#define M_LOG2E 1.4426950408889634074
#define M_LOG10E 0.43429448190325182765
#define M_LN2 0.69314718055994530942
#define M_LN10 2.30258509299404568402
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962
#define M_1_PI 0.31830988618379067154
#define M_2_PI 0.63661977236758134308
#define M_2_SQRTPI 1.12837916709551257390
#define M_SQRT2 1.41421356237309504880
#define M_SQRT1_2 0.70710678118654752440
#define NAN __builtin_nan("")
#define INFINITY __builtin_inf()
#ifndef __ATTR_CONST__
# define __ATTR_CONST__ __attribute__((__const__))
#endif
#ifdef __cplusplus
extern "C" {
#endif
extern double cos(double __x) __ATTR_CONST__;
#define cosf cos
extern double sin(double __x) __ATTR_CONST__;
#define sinf sin
extern double tan(double __x) __ATTR_CONST__;
#define tanf tan
extern double fabs(double __x) __ATTR_CONST__;
#define fabsf fabs
extern double fmod(double __x, double __y) __ATTR_CONST__;
#define fmodf fmod
extern double modf(double __x, double *__iptr);
extern float modff (float __x, float *__iptr);
extern double sqrt(double __x) __ATTR_CONST__;
extern float sqrtf (float) __ATTR_CONST__;
extern double cbrt(double __x) __ATTR_CONST__;
#define cbrtf cbrt
extern double hypot (double __x, double __y) __ATTR_CONST__;
#define hypotf hypot
extern double square(double __x) __ATTR_CONST__;
#define squaref square
extern double floor(double __x) __ATTR_CONST__;
#define floorf floor
extern double ceil(double __x) __ATTR_CONST__;
#define ceilf ceil
extern double frexp(double __x, int *__pexp);
#define frexpf frexp
extern double ldexp(double __x, int __exp) __ATTR_CONST__;
#define ldexpf ldexp
extern double exp(double __x) __ATTR_CONST__;
#define expf exp
extern double cosh(double __x) __ATTR_CONST__;
#define coshf cosh
extern double sinh(double __x) __ATTR_CONST__;
#define sinhf sinh
extern double tanh(double __x) __ATTR_CONST__;
#define tanhf tanh
extern double acos(double __x) __ATTR_CONST__;
#define acosf acos
extern double asin(double __x) __ATTR_CONST__;
#define asinf asin
extern double atan(double __x) __ATTR_CONST__;
#define atanf atan
extern double atan2(double __y, double __x) __ATTR_CONST__;
#define atan2f atan2
extern double log(double __x) __ATTR_CONST__;
#define logf log
extern double log10(double __x) __ATTR_CONST__;
#define log10f log10
extern double pow(double __x, double __y) __ATTR_CONST__;
#define powf pow
extern int isnan(double __x) __ATTR_CONST__;
#define isnanf isnan
extern int isinf(double __x) __ATTR_CONST__;
#define isinff isinf
__ATTR_CONST__ static inline int isfinite (double __x)
{
    unsigned char __exp;
    __asm__ (
 "mov	%0, %C1		\n\t"
 "lsl	%0		\n\t"
 "mov	%0, %D1		\n\t"
 "rol	%0		"
 : "=r" (__exp)
 : "r" (__x) );
    return __exp != 0xff;
}
#define isfinitef isfinite
__ATTR_CONST__ static inline double copysign (double __x, double __y)
{
    __asm__ (
 "bst	%D2, 7	\n\t"
 "bld	%D0, 7	"
 : "=r" (__x)
 : "0" (__x), "r" (__y) );
    return __x;
}
#define copysignf copysign
extern int signbit (double __x) __ATTR_CONST__;
#define signbitf signbit
extern double fdim (double __x, double __y) __ATTR_CONST__;
#define fdimf fdim
extern double fma (double __x, double __y, double __z) __ATTR_CONST__;
#define fmaf fma
extern double fmax (double __x, double __y) __ATTR_CONST__;
#define fmaxf fmax
extern double fmin (double __x, double __y) __ATTR_CONST__;
#define fminf fmin
extern double trunc (double __x) __ATTR_CONST__;
#define truncf trunc
extern double round (double __x) __ATTR_CONST__;
#define roundf round
extern long lround (double __x) __ATTR_CONST__;
#define lroundf lround
extern long lrint (double __x) __ATTR_CONST__;
#define lrintf lrint
#ifdef __cplusplus
}
#endif
#endif
