#pragma once
#include "CommandBase.h"
class SPM:public CommandBase
{
public:
    SPM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
