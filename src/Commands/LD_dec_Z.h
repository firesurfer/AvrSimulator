#pragma once

#include "CommandBase.h"
class LD_dec_Z : public CommandBase
{
public:
    LD_dec_Z(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

