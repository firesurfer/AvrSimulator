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

#ifndef MEMORYMAPPER_H
#define MEMORYMAPPER_H

#include "DataMemory.h"
#include "ProgramMemory.h"
#include <stdexcept>
#include "BitHelpers.h"
#include "ProcessorDefines.h"
class MemoryMapper
{
public:
    MemoryMapper(DataMemory *_memory, ProgramMemory* _pgm_mem);
    DataMemory* getDataMemory();
    ProgramMemory* getProgramMemory();
    uint8_t getRegister(uint32_t reg);
    uint16_t getRegister16(uint32_t reg);
    uint8_t getIORegister(uint32_t reg);
    uint16_t getIORegister16(uint32_t reg);
    uint8_t getData(uint32_t pos);
    uint16_t getData16(uint32_t pos);
    uint8_t getSREG(uint8_t mask=0xFF);
    uint8_t popStack();

    void setRegister(uint32_t reg, uint8_t val);
    void setRegister16(uint32_t reg, uint16_t val);
    void setIORegister(uint32_t reg, uint8_t val);
    void setIORegister16(uint32_t reg, uint16_t val);
    void setData(uint32_t reg, uint8_t val);
    void setData16(uint32_t reg, uint16_t val);
    void setSREG(uint8_t sreg, uint8_t mask=0xFF);
    void pushStack(uint8_t data);

    uint16_t getXReg();
    uint16_t getYReg();
    uint16_t getZReg();
    uint16_t getStackPtr();
    void setXReg(uint16_t data);
    void setYReg(uint16_t data);
    void setZReg(uint16_t data);
    void setStackPtr(uint16_t data);

    ///
    /// \brief watch write accesses to a specific address and print a message or call a function
    /// \param address to be monitored
    /// \param callback to be registered (optional), if empty, write a log message on change
    ///                 callback gets the address, the old and the new value as parameters
    ///
    void watch(uint32_t address, std::function<void(uint32_t, uint8_t, uint8_t, uint8_t &)> callback=nullptr){
        if(data_memory)
            data_memory->watchWrite(address, callback);
    }


private:
    DataMemory* data_memory;
    ProgramMemory* program_memory;
};

typedef struct{
    uint16_t addr;
    uint16_t bit;
}register_bit_t;

#endif // MEMORYMAPPER_H
