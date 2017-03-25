#pragma once
#include "CommandBase.h"
class STD_Z:public CommandBase
{
public:
    STD_Z(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
