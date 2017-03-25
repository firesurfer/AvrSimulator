#pragma once
#include "CommandBase.h"
class RETI:public CommandBase
{
public:
    RETI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
