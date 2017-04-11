#pragma once

#include "CommandBase.h"
class ST_Z_inc : public CommandBase
{
public:
    ST_Z_inc(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

