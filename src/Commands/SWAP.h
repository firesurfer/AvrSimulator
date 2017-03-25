#pragma once
#include "CommandBase.h"
class SWAP:public CommandBase
{
public:
    SWAP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
