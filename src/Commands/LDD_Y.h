#pragma once
#include "CommandBase.h"
class LDD_Y:public CommandBase
{
public:
    LDD_Y(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
