#pragma once

#include "CommandBase.h"
class LD_X : public CommandBase
{
public:
    LD_X(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

