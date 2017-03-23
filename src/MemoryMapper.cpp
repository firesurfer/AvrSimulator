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

void MemoryMapper::getRegister(uint8_t &val, uint16_t reg)
{
    val = data_memory->Get(reg);
}

void MemoryMapper::getIORegister(uint8_t &val, uint16_t reg)
{
    val = data_memory->Get(reg);
}

void MemoryMapper::getSRAM(uint8_t val, uint16_t pos)
{
    val = data_memory->Get(pos);
}
