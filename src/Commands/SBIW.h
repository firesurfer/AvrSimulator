#pragma once
#include "CommandBase.h"
class SBIW:public CommandBase
{
public:
    SBIW(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
