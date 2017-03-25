#pragma once
#include "CommandBase.h"
class WDR:public CommandBase
{
public:
    WDR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
