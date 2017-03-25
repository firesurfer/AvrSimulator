#pragma once
#include "CommandBase.h"
class IN:public CommandBase
{
public:
    IN(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
