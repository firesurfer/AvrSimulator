#pragma once

#include "CommandBase.h"
class LD_X_PreDecr : public CommandBase
{
public:
    LD_X_PreDecr(MemoryMapper* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
     virtual uint16_t CommandMask();
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

