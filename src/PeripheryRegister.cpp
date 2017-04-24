#include "PeripheryRegister.h"

#include "Periphery/IOPort.h"
#include "Periphery/Uart.h"
void PeripheryRegister::registerPeriphery(PeripheryHandler *handler, MemoryMapper *mapper, InterruptController *intController)
{
    handler->addPeripheryElement(new Uart(mapper));

    intvector_t uartVector;
    uartVector.clearflag = false;
    uartVector.flagaddr = 0x2B;
    uartVector.flagbit = 5;
    uartVector.maskaddr = 0x2A;
    uartVector.maskbit = 5;
    uartVector.vectoraddress = 0x1C;
    intController->addInterruptVector(uartVector);
}
