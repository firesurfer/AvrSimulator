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
    uint8_t getIORegister(uint32_t reg);
    uint8_t getSRAM(uint32_t pos);

    void setRegister(uint32_t reg, uint8_t val);
    void setIORegister(uint32_t reg, uint8_t val);
    void setSRAM(uint32_t reg, uint8_t val);
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

private:
    DataMemory* data_memory;
    ProgramMemory* program_memory;
};

#endif // MEMORYMAPPER_H
