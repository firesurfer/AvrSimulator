#pragma once
#include "CommandBase.h"
class STD_Y:public CommandBase
{
public:
    STD_Y(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
