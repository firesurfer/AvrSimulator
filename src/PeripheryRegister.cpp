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
#include "Periphery/Timer.h"

void PeripheryRegister::registerPeriphery(PeripheryHandler *handler, MemoryMapper *mapper, InterruptController *intController)
{
    handler->addPeripheryElement(new Uart(mapper, UDR, {UCSRA, UDRE}, {UCSRA, RXC}, {UCSRA, 3}));

    intvector_t uartVector;
    uartVector.clearflag = false;
    uartVector.flag = {UCSRA, UDRE};
    uartVector.mask = {UCSRB, UDRIE};
    uartVector.vectoraddress = USART_UDRE_vect_num*2;//JMP needs 2 words instead 1 word for RJMP
    intController->addInterruptVector(uartVector);
    uartVector.clearflag = false;
    uartVector.flag = {UCSRA, RXC};
    uartVector.mask = {UCSRB, RXCIE};
    uartVector.vectoraddress = USART_RXC_vect_num*2;
    intController->addInterruptVector(uartVector);

    handler->addPeripheryElement(new IOPort(mapper, {"PORTA", DDRA, PORTA, PINA}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTB", DDRB, PORTB, PINB}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTC", DDRC, PORTC, PINC}));
    handler->addPeripheryElement(new IOPort(mapper, {"PORTD", DDRD, PORTD, PIND}));

    handler->addPeripheryElement(new Timer(mapper, {TCNT0, {TCCR0, CS00}, {TIFR, TOV0}, {0,1,8,64,256,1024,1,1}}, false));
    handler->addPeripheryElement(new Timer(mapper, {TCNT1, {TCCR1B, CS10}, {TIFR, TOV1}, {0,1,8,64,256,1024,1,1}}, true));
    handler->addPeripheryElement(new Timer(mapper, {TCNT2, {TCCR2, CS20}, {TIFR, TOV2}, {0,1,8,32,64,128,256,1024}}, false));
    intvector_t timerVector;
    timerVector.clearflag = true;
    timerVector.flag = {TIFR, TOV0};
    timerVector.mask = {TIMSK, TOIE0};
    timerVector.vectoraddress = TIMER0_OVF_vect_num*2;
    intController->addInterruptVector(timerVector);
    timerVector.flag = {TIFR, TOV1};
    timerVector.mask = {TIMSK, TOIE1};
    timerVector.vectoraddress = TIMER1_OVF_vect_num*2;
    intController->addInterruptVector(timerVector);
    timerVector.flag = {TIFR, TOV2};
    timerVector.mask = {TIMSK, TOIE2};
    timerVector.vectoraddress = TIMER2_OVF_vect_num*2;
    intController->addInterruptVector(timerVector);
}
