#ifndef PROCESSORDEFINES_H
#define PROCESSORDEFINES_H

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
#define MCUCR   0x55
#define MCUCSR  0x54
#define SREG    0x5F
#define SPH     0x5E
#define SPL     0x5D

#define PORTA   0x3B
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

#define UNUSED(x) (void)(x)

#endif // PROCESSORDEFINES_H
