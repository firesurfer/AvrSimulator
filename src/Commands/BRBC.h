#pragma once
#include "CommandBase.h"
class BRBC:public CommandBase
{
public:
    BRBC(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
