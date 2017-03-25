#pragma once
#include "CommandBase.h"
class BSET:public CommandBase
{
public:
    BSET(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
