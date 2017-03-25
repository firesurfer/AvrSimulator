#pragma once
#include "CommandBase.h"
class LDI:public CommandBase
{
public:
    LDI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
