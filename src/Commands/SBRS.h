#pragma once
#include "CommandBase.h"
class SBRS:public CommandBase
{
public:
    SBRS(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
