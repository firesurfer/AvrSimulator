#pragma once
#include "CommandBase.h"
class EIJMP:public CommandBase
{
public:
    EIJMP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
