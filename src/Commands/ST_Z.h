#pragma once

#include "CommandBase.h"
class ST_Z : public CommandBase
{
public:
    ST_Z(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

