#include "PeripheryRegister.h"

#include "Periphery/IOPort.h"
#include "Periphery/Uart.h"
PeripheryRegister::PeripheryRegister(PeripheryHandler *handler, MemoryMapper *mapper)
{
    handler->addPeripheryElement(new Uart(mapper));
}
