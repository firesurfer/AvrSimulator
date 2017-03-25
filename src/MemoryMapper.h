#ifndef MEMORYMAPPER_H
#define MEMORYMAPPER_H

#include "DataMemory.h"
#include "ProgramMemory.h"
#include <stdexcept>

class MemoryMapper
{
public:
    MemoryMapper(DataMemory *_memory, ProgramMemory* _pgm_mem);
    DataMemory* getDataMemory();
    ProgramMemory* getProgramMemory();
    uint8_t getRegister(uint32_t reg);
    uint8_t getIORegister(uint32_t reg);
    uint8_t getSRAM(uint32_t pos);
    uint8_t getSREG(uint8_t mask=0xFF);
    uint8_t popStack();

    void setRegister(uint32_t reg, uint8_t val);
    void setIORegister(uint32_t reg, uint8_t val);
    void setSRAM(uint32_t reg, uint8_t val);
    void setSREG(uint8_t sreg, uint8_t mask=0xFF);
    void pushStack(uint8_t data);
private:
    DataMemory* data_memory;
    ProgramMemory* program_memory;
};

#endif // MEMORYMAPPER_H
