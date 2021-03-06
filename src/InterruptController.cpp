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

#include "InterruptController.h"

InterruptController::InterruptController(MemoryMapper *_mem_mapper)
{
    this->memoryMapper = _mem_mapper;
    this->dataMem = _mem_mapper->getDataMemory();
}

uint32_t InterruptController::handleInterrupts(uint32_t cycles, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    if(!memoryMapper->getSREG(MASK_I))
        return 0;
    if(flags.skipNextInstruction)
        return 0;
    for(auto & it: this->interruptVectors)
    {
        intvector_t element = it.second;
        if(dataMem->getDirect(element.mask.addr)&(1<<element.mask.bit)){
            if(dataMem->getDirect(element.flag.addr)&(1<<element.flag.bit)){
                LOG(Info)<<"Interrupt started:\n";
                uint8_t low_byte = (uint8_t)ProgramCounter;
                uint8_t high_byte = (uint8_t)((ProgramCounter) >> 8);
                memoryMapper->pushStack(low_byte);
                memoryMapper->pushStack(high_byte);
                memoryMapper->setSREG(0,MASK_I);
                ProgramCounter = element.vectoraddress * WORDS_PER_INT;
                if(element.clearflag){
                    uint8_t flags = dataMem->getDirect(element.flag.addr);
                    flags &= ~(1<<element.flag.bit);
                    dataMem->setDirect(element.flag.addr,flags);
                }
                return 4;
            }
        }
    }
    return 0;
}

void InterruptController::addInterruptVector(intvector_t element)
{
    this->interruptVectors.emplace(element.vectoraddress,element);
}
