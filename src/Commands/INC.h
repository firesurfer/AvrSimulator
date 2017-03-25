#pragma once
#include "CommandBase.h"
class INC:public CommandBase
{
public:
    INC(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
