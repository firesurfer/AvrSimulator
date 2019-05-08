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

#ifndef IOPORT_H
#define IOPORT_H
#include "PeripheryElement.h"

typedef uint16_t DataDirection;
typedef uint16_t DataRegister;
typedef uint16_t InputRegister;

struct Port
{
    std::string portName;
    DataDirection dataDirection;
    DataRegister dataRegister;
    InputRegister inputRegister;
};

enum class IODirection
{
    INPUT = 0,
    OUTPUT = 1
};

class IOPort: public PeripheryElement
{
public:
    IOPort(MemoryMapper* mapper, Port _port);
    void handle(uint32_t cycles);
private:
    Port port;

    std::vector<IODirection> portDirections;
    std::vector<bool> portData;
    std::vector<bool> portInput;

    uint8_t lastDDR = 0;
    uint8_t lastPORT = 0;
    uint8_t lastPIN = 0;

    void onPinChange(int32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref);
};

#endif // IOPORT_H
