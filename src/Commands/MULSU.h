#pragma once
#include "CommandBase.h"
class MULSU:public CommandBase
{
public:
    MULSU(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
