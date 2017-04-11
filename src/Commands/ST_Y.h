#pragma once

#include "CommandBase.h"
class ST_Y : public CommandBase
{
public:
    ST_Y(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

