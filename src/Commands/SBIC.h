#pragma once
#include "CommandBase.h"
class SBIC:public CommandBase
{
public:
    SBIC(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
