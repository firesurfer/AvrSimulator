#pragma once
#include "CommandBase.h"
class CP:public CommandBase
{
public:
    CP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
