#include <avr/io.h>
int main(void)
{
	volatile uint8_t a,b,c;
	a = 5;
	b = 6;
	c = a*b;
	return 0;
}
