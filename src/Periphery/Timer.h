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

#ifndef TIMER_H
#define TIMER_H

#include "PeripheryElement.h"

typedef struct{
    uint16_t tcnt;
    register_bit_t cs0;
    register_bit_t tov;
    uint16_t presc_table[8];
}timer_registers_t;

class Timer:public PeripheryElement
{
public:
    Timer(MemoryMapper* mapper, timer_registers_t _timer, bool _bit16);
    void handle(uint32_t cycles);

private:
    void onTov(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref);
    uint16_t readReg(uint32_t addr){if(bit16)return dataMem->getDirect16(addr); else return dataMem->getDirect(addr);}
    void writeReg(uint32_t addr, uint16_t val){if(bit16)dataMem->setDirect16(addr,val); else dataMem->setDirect(addr,val);}
    timer_registers_t timer;
    uint16_t presc_cnt;
    uint16_t presc_top;
    int32_t timer_top;
    bool bit16;
};

#endif // UART_H
