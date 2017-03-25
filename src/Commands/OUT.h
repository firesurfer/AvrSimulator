#pragma once
#include "CommandBase.h"
class OUT:public CommandBase
{
public:
    OUT(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
