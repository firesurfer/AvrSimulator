#pragma once
#include "CommandBase.h"
class SBI:public CommandBase
{
public:
    SBI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};


