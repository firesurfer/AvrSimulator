#pragma once
#include "CommandBase.h"
class NEG:public CommandBase
{
public:
    NEG(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
