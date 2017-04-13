#include "PeripheryRegister.h"

#include "Periphery/IOPort.h"
#include "Periphery/Uart.h"
void PeripheryRegister::registerPeriphery(PeripheryHandler *handler, MemoryMapper *mapper)
{
    handler->addPeripheryElement(new Uart(mapper));
}
