/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef PROCESSORDEFINES_H
#define PROCESSORDEFINES_H

#define _AVR_IO_H_
#define _SFR_IO8(addr) ((addr)+0x20)
#define _SFR_IO16(addr) ((addr)+0x20)
#include "avr/iom32.h"

#define DEBUG

#define X_H 27
#define X_L 26
#define Y_H 29
#define Y_L 28
#define Z_H 31
#define Z_L 30

#define R0 0x00
#define R31 0x1F


//These addresses locate the io registers in the global address space
//These are for a atmega32
//#define MCUCR   0x55
//#define MCUCSR  0x54
#define SREG    0x5F
#define SPH     0x5E
#define SPL     0x5D


#define SREG_I 7
#define SREG_T 6
#define SREG_H 5
#define SREG_S 4
#define SREG_V 3
#define SREG_N 2
#define SREG_Z 1
#define SREG_C 0

#define MASK_I (1<<SREG_I)
#define MASK_T (1<<SREG_T)
#define MASK_H (1<<SREG_H)
#define MASK_S (1<<SREG_S)
#define MASK_V (1<<SREG_V)
#define MASK_N (1<<SREG_N)
#define MASK_Z (1<<SREG_Z)
#define MASK_C (1<<SREG_C)


#define UNUSED(x) (void)(x)

#if _VECTORS_SIZE & 0x2 //if size of interrupt vector table is not divisible by 4, 1 word per interrupt is used (rjmp)
#define WORDS_PER_INT 1
#endif

#ifndef WORDS_PER_INT
#define WORDS_PER_INT 2 //Atmega32 uses 2 instruction words per interrupt (jmp)
#endif

#endif // PROCESSORDEFINES_H
