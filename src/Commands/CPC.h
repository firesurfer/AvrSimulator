#pragma once
#include "CommandBase.h"
class CPC:public CommandBase
{
public:
    CPC(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
