#pragma once
#include "CommandBase.h"
class COM:public CommandBase
{
public:
    COM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
