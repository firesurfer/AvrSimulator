#ifndef IOPORT_H
#define IOPORT_H
#include "PeripheryElement.h"
typedef enum
{
    PORT_A = PORTA,
    PORT_B = PORTB,
    PORT_C = PORTC,
    PORT_D = PORTD
}Port;

class IOPort: public PeripheryElement
{
public:
    IOPort(MemoryMapper* mapper, Port _port);
    void handle(uint32_t cycles);
private:
    Port port;
};

#endif // IOPORT_H
