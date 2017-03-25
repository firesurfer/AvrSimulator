#pragma once
#include "CommandBase.h"
class LPM:public CommandBase
{
public:
    LPM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
