#pragma once
#include "CommandBase.h"
class LAS:public CommandBase
{
public:
    LAS(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};