#ifndef PROCESSORDEFINES_H
#define PROCESSORDEFINES_H

#define X_H 27
#define X_L 26
#define Y_H 29
#define Y_L 28
#define Z_H 31
#define Z_L 30

#define R0 0x00
#define R31 0x1F

#define SPECIAL_REGISTERS_SIZE 5
#define MCUCR 0x55
#define MCUCSR 0x54
#define SREG 0x5F
#define SPH 0x5E
#define SPL 0x5D

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

#define OCDR 0x51


#endif // PROCESSORDEFINES_H
