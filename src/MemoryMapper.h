#ifndef MEMORYMAPPER_H
#define MEMORYMAPPER_H

#include "DataMemory.h"
#include "ProgramMemory.h"

class MemoryMapper
{
public:
    MemoryMapper(DataMemory *_memory, ProgramMemory* _pgm_mem);
};

#endif // MEMORYMAPPER_H
