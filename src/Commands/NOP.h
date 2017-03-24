#pragma once

#include "CommandBase.h"
class NOP:public CommandBase
{
public:
    NOP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t  instruction, uint16_t &ProgramCounter);

};
