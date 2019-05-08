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
typedef enum
{
    PORT_A = PORTA,
    PORT_B = PORTB,
    PORT_C = PORTC,
    PORT_D = PORTD
}Port;

class IOPort: public PeripheryElement
{
public:
    IOPort(MemoryMapper* mapper, Port _port);
    void handle(uint32_t cycles);
private:
    Port port;
};

#endif // IOPORT_H
