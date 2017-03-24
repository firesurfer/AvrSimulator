#pragma once

#include "CommandBase.h"
class EOR:public CommandBase
{
public:
    EOR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t  instruction, uint16_t &ProgramCounter);

};
