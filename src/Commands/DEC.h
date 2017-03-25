#pragma once
#include "CommandBase.h"
class DEC:public CommandBase
{
public:
    DEC(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
