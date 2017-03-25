#pragma once
#include "CommandBase.h"
class BRBS:public CommandBase
{
public:
    BRBS(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
