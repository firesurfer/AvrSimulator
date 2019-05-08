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

#include "MemoryMapper.h"
#include "DataMemory.h"

using namespace std;

MemoryMapper::MemoryMapper(DataMemory* _memory, ProgramMemory *_pgm_mem)
{
    this->data_memory = _memory;
    this->program_memory = _pgm_mem;
}

DataMemory *MemoryMapper::getDataMemory()
{
    return this->data_memory;
}

ProgramMemory *MemoryMapper::getProgramMemory()
{
    return this->program_memory;
}

uint8_t MemoryMapper::getRegister(uint32_t reg)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    uint8_t value = data_memory->get(reg);
    LOG(Debug3) << "Get r" << dec << reg << ": 0x" << hex << (int)value << endl;
    return value;
}

uint16_t MemoryMapper::getRegister16(uint32_t reg)
{
    return (uint16_t)getRegister(reg+1)<<8|getRegister(reg);
}

uint8_t MemoryMapper::getIORegister(uint32_t reg)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    uint8_t value = data_memory->get(reg+0x20);
    LOG(Debug3) << "Get IOReg 0x" << hex << reg << ": 0x" << (int)value << endl;
    return value;
}

uint16_t MemoryMapper::getIORegister16(uint32_t reg)
{
    return (uint16_t)getIORegister(reg+1)<<8|getIORegister(reg);
}

uint8_t MemoryMapper::getData(uint32_t pos)
{
    uint8_t value = data_memory->get(pos);
    LOG(Debug3) << "Get data address 0x" << hex << pos << ": 0x" << (int)value << endl;
    return value;
}

uint16_t MemoryMapper::getData16(uint32_t pos)
{
    return (uint16_t)getData(pos+1)<<8|getData(pos);
}

uint8_t MemoryMapper::getSREG(uint8_t mask)
{
    return data_memory->get(0x5F)&mask;
}

uint8_t MemoryMapper::popStack()
{
    uint16_t SP=getStackPtr();
    SP++;
    setStackPtr(SP);
    uint8_t value = data_memory->get(SP);
    LOG(Debug3) << "Pop Stack 0x" << hex << SP << ": 0x" << (int)value << endl;
    return value;
}

void MemoryMapper::setRegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    data_memory->get(reg,val);
}

void MemoryMapper::setRegister16(uint32_t reg, uint16_t val)
{
    setRegister(reg,val);
    setRegister(reg+1,val>>8);
}

void MemoryMapper::setIORegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    data_memory->get(reg+0x20,val);
    LOG(Debug3) << "Set io address 0x" << hex << reg << ": 0x" << (int)val << endl;
}

void MemoryMapper::setIORegister16(uint32_t reg, uint16_t val)
{
    setIORegister(reg,val);
    setIORegister(reg+1,val>>8);
}

void MemoryMapper::setData(uint32_t reg, uint8_t val)
{
    data_memory->get(reg,val);
}

void MemoryMapper::setData16(uint32_t reg, uint16_t val)
{
    setData(reg,val);
    setData(reg+1,val>>8);
}

void MemoryMapper::setSREG(uint8_t sreg, uint8_t mask)
{
    data_memory->get(0x5F,getSREG(~mask)|(mask&sreg));
}

void MemoryMapper::pushStack(uint8_t data)
{
    uint16_t SP=getStackPtr();
    if(SP<=0x60){
        throw std::overflow_error("Stackoverflow, did you initialize the stackpointer?");
    }
    data_memory->get(SP,data);
    SP--;
    setStackPtr(SP);
}

uint16_t MemoryMapper::getXReg()
{
    return getRegister16(X_L);
}

uint16_t MemoryMapper::getYReg()
{
    return getRegister16(Y_L);
}

uint16_t MemoryMapper::getZReg()
{
    return getRegister16(Z_L);
}

uint16_t MemoryMapper::getStackPtr()
{
    return getData16(SPL);
}

void MemoryMapper::setXReg(uint16_t data)
{
    setRegister16(X_L,data);
}

void MemoryMapper::setYReg(uint16_t data)
{
    setRegister16(Y_L,data);
}

void MemoryMapper::setZReg(uint16_t data)
{
    setRegister16(Z_L,data);
}

void MemoryMapper::setStackPtr(uint16_t data)
{
    setData16(SPL,data);
}


