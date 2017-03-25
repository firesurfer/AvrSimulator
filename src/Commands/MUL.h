#pragma once
#include "CommandBase.h"
class MUL:public CommandBase
{
public:
    MUL(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
