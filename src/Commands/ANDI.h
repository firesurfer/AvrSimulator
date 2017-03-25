#pragma once
#include "CommandBase.h"
class ANDI:public CommandBase
{
public:
    ANDI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
