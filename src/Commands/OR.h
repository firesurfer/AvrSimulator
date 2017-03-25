#pragma once
#include "CommandBase.h"
class OR:public CommandBase
{
public:
    OR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
