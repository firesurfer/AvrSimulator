#ifndef UART_H
#define UART_H

#include "PeripheryElement.h"

class Uart:public PeripheryElement
{
public:
    Uart(MemoryMapper* mapper);
    void handle(uint32_t cycles);

private:
    void onChange(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref);
    void onRead(uint32_t addr, uint8_t val);
    std::string buffer;
    uint32_t receiveCycles;
};

#endif // UART_H
