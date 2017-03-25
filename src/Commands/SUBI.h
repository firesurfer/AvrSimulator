#pragma once
#include "CommandBase.h"
class SUBI:public CommandBase
{
public:
    SUBI(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
