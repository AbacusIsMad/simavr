#define PP_NARG(...)    PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
#define PP_NARG_(...)   PP_ARG_N(__VA_ARGS__)

#define PP_ARG_N( \
        _1, _2, _3, _4, _5, _6, _7, _8, _9,_10,  \
        _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
        _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
        _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
        _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
        _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
        _61,_62,_63,N,...) N

#define PP_RSEQ_N() \
        63,62,61,60,                   \
        59,58,57,56,55,54,53,52,51,50, \
        49,48,47,46,45,44,43,42,41,40, \
        39,38,37,36,35,34,33,32,31,30, \
        29,28,27,26,25,24,23,22,21,20, \
        19,18,17,16,15,14,13,12,11,10, \
        9,8,7,6,5,4,3,2,1,0


/* need extra level to force extra eval */
#define Paste(a,b) a ## b
#define XPASTE(a,b) Paste(a,b)

#define XPASTE2(a,b) Paste(a,b);


/* APPLYXn variadic X-Macro by M Joshua Ryan      */
/* Free for all uses. Don't be a jerk.            */
/* I got bored after typing 15 of these.          */
/* You could keep going upto 64 (PPNARG's limit). */
#define APPLYX1(fname,a)           X(fname,a)
#define APPLYX2(fname,a,b)         X(fname,a) X(fname,b)
#define APPLYX3(fname,a,b,c)       X(fname,a) X(fname,b) X(fname,c)
#define APPLYX4(fname,a,b,c,d)     X(fname,a) X(fname,b) X(fname,c) X(fname,d)
#define APPLYX5(fname,a,b,c,d,e)   X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e)
#define APPLYX6(fname,a,b,c,d,e,f) X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f)
#define APPLYX7(fname,a,b,c,d,e,f,g) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g)
#define APPLYX8(fname,a,b,c,d,e,f,g,h) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h)
#define APPLYX9(fname,a,b,c,d,e,f,g,h,i) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i)
#define APPLYX10(fname,a,b,c,d,e,f,g,h,i,j) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j)
#define APPLYX11(fname,a,b,c,d,e,f,g,h,i,j,k) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j) X(fname,k)
#define APPLYX12(fname,a,b,c,d,e,f,g,h,i,j,k,l) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j) X(fname,k) X(fname,l)
#define APPLYX13(fname,a,b,c,d,e,f,g,h,i,j,k,l,m) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j) X(fname,k) X(fname,l) X(fname,m)
#define APPLYX14(fname,a,b,c,d,e,f,g,h,i,j,k,l,m,n) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j) X(fname,k) X(fname,l) X(fname,m) X(fname,n)
#define APPLYX15(fname,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o) \
    X(fname,a) X(fname,b) X(fname,c) X(fname,d) X(fname,e) X(fname,f) X(fname,g) X(fname,h) X(fname,i) X(fname,j) X(fname,k) X(fname,l) X(fname,m) X(fname,n) X(fname,o)
#define APPLYX_(M, fname,...) M(fname,__VA_ARGS__)
#define APPLYXn(fname,...) APPLYX_(XPASTE(APPLYX, PP_NARG(__VA_ARGS__)), fname, __VA_ARGS__)


#define ATTRIB_A "a"
#define ATTRIB_B "b"
#define ATTRIB_C "c"



#define X(fname,a) XPASTE2(a, _ ## fname)

#define ATTRIBS(fname,...) APPLYXn(fname,__VA_ARGS__)

#define BIND_AVR_LABELS "AVR_BIND_"

#define UUT_WRAP_FUNC(fname, statement)\
	asm volatile(BIND_AVR_LABELS fname "_BEGIN:"); \
	{statement;} \
	asm volatile("BIND_AVR_LABELS fname "_END:"");

UUT_WRAP_FUNC(woah, a = woah(arg_buffer[0], arg_buffer[1]));
