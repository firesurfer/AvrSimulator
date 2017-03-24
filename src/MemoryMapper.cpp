#include "MemoryMapper.h"
#include "DataMemory.h"
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
    return data_memory->Get(reg);
}

uint8_t MemoryMapper::getIORegister(uint32_t reg)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    return data_memory->Get(reg+0x20);
}

uint8_t MemoryMapper::getSRAM(uint32_t pos)
{
    return data_memory->Get(pos);
}

void MemoryMapper::setRegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x20){
        throw std::out_of_range("Only 32 Processorregisters available");
    }
    data_memory->Set(reg,val);
}

void MemoryMapper::setIORegister(uint32_t reg, uint8_t val)
{
    if(reg>=0x40){
        throw std::out_of_range("Only 64 IO-Registers available");
    }
    data_memory->Set(reg+0x20,val);
}

void MemoryMapper::setSRAM(uint32_t reg, uint8_t val)
{
    data_memory->Set(reg,val);
}
