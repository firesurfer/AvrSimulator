#pragma once
#include "CommandBase.h"
class MOV:public CommandBase
{
public:
    MOV(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};