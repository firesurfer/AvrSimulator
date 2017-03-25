#pragma once
#include "CommandBase.h"
class BCLR:public CommandBase
{
public:
    BCLR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
