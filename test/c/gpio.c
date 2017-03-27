#include  <avr/io.h>

int main(void)
{
    DDRB |= (1<<PINB0) | (1<<PINB1);
    PORTB |= (1<<PINB0) | (1<<PINB1);
    return 0;
}
