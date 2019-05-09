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
#include "iom32.h"

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

/*#define PORTA   0x3B
#define DDRA    0x3A
#define PINA    0x39
#define PORTB   0x38
#define DDRB    0x37
#define PINB    0x36
#define PORTC   0x35
#define DDRC    0x34
#define PINC    0x33
#define PORTD   0x32
#define DDRD    0x31
#define PIND    0x30

#define UDR     0x2C
#define UCSRA   0x2B
#define UCSRB   0x2A
#define UBRRL   0x29

#define ACSR    0x28
#define ADMUX   0x27
#define ADCSRA  0x26
#define ADCH    0x25
#define ADCL    0x24*/


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

//#define OCDR 0x51

#define UNUSED(x) (void)(x)

#endif // PROCESSORDEFINES_H
