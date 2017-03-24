#pragma once

#include "CommandBase.h"
class LDS_SRAM : public CommandBase
{
public:
    LDS_SRAM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

