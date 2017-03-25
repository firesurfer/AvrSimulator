#pragma once
#include "CommandBase.h"
class RCALL:public CommandBase
{
public:
    RCALL(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
