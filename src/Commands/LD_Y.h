#pragma once

#include "CommandBase.h"
class LD_Y : public CommandBase
{
public:
    LD_Y(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

