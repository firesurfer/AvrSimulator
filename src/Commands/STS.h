#pragma once

#include "CommandBase.h"
class STS : public CommandBase
{
public:
    STS(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

