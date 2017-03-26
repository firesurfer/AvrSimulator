#pragma once

#include "CommandBase.h"
class ST_Y_inc : public CommandBase
{
public:
    ST_Y_inc(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

