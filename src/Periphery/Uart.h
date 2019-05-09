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

#ifndef UART_H
#define UART_H

#include "PeripheryElement.h"

class Uart:public PeripheryElement
{
public:
    Uart(MemoryMapper* mapper, uint16_t _udr, register_bit_t _udre, register_bit_t _rxc, register_bit_t _dor);
    void handle(uint32_t cycles);

private:
    void onChange(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref);
    void onStatus(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref);
    void onRead(uint32_t addr, uint8_t val);
    std::string buffer;
    uint32_t receiveCycles;
    uint16_t udr;
    register_bit_t udre;
    register_bit_t rxc;
    register_bit_t dor;
};

#endif // UART_H
