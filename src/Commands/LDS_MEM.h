#pragma once

#include "CommandBase.h"
class LDS_MEM : public CommandBase
{
public:
    LDS_MEM(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

