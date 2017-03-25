#pragma once
#include "CommandBase.h"
class SLEEP:public CommandBase
{
public:
    SLEEP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
