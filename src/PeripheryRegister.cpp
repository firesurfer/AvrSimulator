/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
    uartVector.clearflag = false;
    uartVector.flagaddr = 0x2B;
    uartVector.flagbit = 7;
    uartVector.maskaddr = 0x2A;
    uartVector.maskbit = 7;
    uartVector.vectoraddress = 0x1A;
    intController->addInterruptVector(uartVector);

    handler->addPeripheryElement(new IOPort(mapper, {"PORTA", DDRA, PORTA, PINA}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTB", DDRB, PORTB, PINB}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTC", DDRC, PORTC, PINC}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTD", DDRD, PORTD, PIND}));
}
