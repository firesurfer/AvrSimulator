#pragma once
#include "CommandBase.h"
class CPSE:public CommandBase
{
public:
    CPSE(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
