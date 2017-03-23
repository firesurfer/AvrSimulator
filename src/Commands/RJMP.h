#pragma once

#include "CommandBase.h"
class RJMP:public CommandBase
{
public:
    RJMP(MemoryMapper* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
     virtual uint16_t CommandMask();
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

