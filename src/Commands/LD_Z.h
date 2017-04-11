#pragma once

#include "CommandBase.h"
class LD_Z : public CommandBase
{
public:
    LD_Z(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

