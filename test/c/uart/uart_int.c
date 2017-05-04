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
      int c=uart_getc();
      if((c&0xFF00)==UART_FRAME_ERROR)uart_puts("FrameError\n");
      if((c&0xFF00)==UART_OVERRUN_ERROR)uart_puts("OverrunError\n");
      if((c&0xFF00)==UART_BUFFER_OVERFLOW)uart_puts("BufferOverflow\n");
      if(c!=UART_NO_DATA)uart_putc(c);
    }
    return 0;
}
