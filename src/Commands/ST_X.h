#pragma once

#include "CommandBase.h"
class ST_X : public CommandBase
{
public:
    ST_X(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

