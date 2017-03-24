#pragma once

#include "CommandBase.h"
class LDS_MEM : public CommandBase
{
public:
    LDS_MEM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};

