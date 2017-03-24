#pragma once

#include "CommandBase.h"
class RJMP:public CommandBase
{
public:
    RJMP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter) override;
};


