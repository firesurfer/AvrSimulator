#include  <avr/io.h>

int main(void)
{
    DDRA |= (1<<PB0) | (1<<PB1);
    DDRB |= (1<<PB0) | (1<<PB1);
    PORTB |= (1<<PB0) | (1<<PB1);
    PINB |= (1<<PB0);
    while(1)
    {
       //PORTB &= ~(1<<PB0);
        PINB |= (1<<PB0);
    }
    return 0;
}
