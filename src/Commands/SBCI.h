#pragma once
#include "CommandBase.h"
class SBCI:public CommandBase
{
public:
    SBCI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
