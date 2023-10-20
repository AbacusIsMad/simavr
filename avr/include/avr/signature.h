#ifndef _AVR_SIGNATURE_H_
#define _AVR_SIGNATURE_H_ 1
#ifndef __ASSEMBLER__
#include <avr/io.h>
#if defined(SIGNATURE_0) && defined(SIGNATURE_1) && defined(SIGNATURE_2)
const unsigned char __signature[3]
__attribute__((__used__, __section__(".signature"))) =
        { SIGNATURE_2, SIGNATURE_1, SIGNATURE_0 };
#endif
#endif
#endif
