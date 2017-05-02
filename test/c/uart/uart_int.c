#include  <avr/io.h>
#include <avr/pgmspace.h>
#include "uart.h"
#include <avr/interrupt.h>
/* UART-Init Bsp. ATmega16 */

int main(void)
{
sei();
    uart_init(UART_BAUD_SELECT(9600,16000000ul));
    uart_puts("Hallo");
    uart_putc(' ');
    uart_puts_p(PSTR("Welt!\n"));
    while(1)
    {
    }
    return 0;
}
