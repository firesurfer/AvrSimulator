#pragma once

#include "CommandBase.h"
class LD_Z_inc : public CommandBase
{
public:
    LD_Z_inc(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

