#pragma once
#include "CommandBase.h"
class AND:public CommandBase
{
public:
    AND(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
