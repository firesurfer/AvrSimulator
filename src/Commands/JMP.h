#pragma once

#include "CommandBase.h"
class JMP:public CommandBase
{
public:
    JMP(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t  instruction, uint16_t &ProgramCounter);

};
