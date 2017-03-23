#ifndef MEMORYMAPPER_H
#define MEMORYMAPPER_H

#include "DataMemory.h"
#include "ProgramMemory.h"

class MemoryMapper
{
public:
    MemoryMapper(DataMemory *_memory, ProgramMemory* _pgm_mem);
    DataMemory* getDataMemory();
    ProgramMemory* getProgramMemory();
    void getRegister(uint8_t &val, uint16_t reg);
    void getIORegister(uint8_t& val, uint16_t reg);
    void getSRAM(uint8_t val, uint16_t pos);
private:
    DataMemory* data_memory;
    ProgramMemory* program_memory;
};

#endif // MEMORYMAPPER_H
