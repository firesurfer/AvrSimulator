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

#ifndef INTERRUPTCONTROLLER_H
#define INTERRUPTCONTROLLER_H

#include "MemoryMapper.h"
#include <map>
#include <ProcessorFlags.h>

typedef struct{
    uint32_t vectoraddress;
    uint32_t flagaddr;
    uint32_t flagbit;
    uint32_t maskaddr;
    uint32_t maskbit;
    bool clearflag;
    //priority
} intvector_t;

class InterruptController
{
public:
    InterruptController(MemoryMapper* _mem_mapper);
    uint32_t handleInterrupts(uint32_t cycles, uint16_t &ProgramCounter, ProcessorFlags &flags);
    void addInterruptVector(intvector_t element);
private:
    MemoryMapper* memoryMapper;
    DataMemory* dataMem;
    std::multimap<uint32_t,intvector_t> interruptVectors;
};

#endif // PERIPHERYHANDLER_H
