#pragma once
#include "CommandBase.h"
class ADD:public CommandBase
{
public:
    ADD(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
