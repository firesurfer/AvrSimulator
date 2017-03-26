#ifndef UART_H
#define UART_H

#include "PeripheryElement.h"

class Uart:public PeripheryElement
{
public:
    Uart(MemoryMapper* mapper);
    void handle();
};

#endif // UART_H
