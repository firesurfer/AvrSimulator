#pragma once
#include "CommandBase.h"
class LSR:public CommandBase
{
public:
    LSR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
