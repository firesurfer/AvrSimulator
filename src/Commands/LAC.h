#pragma once
#include "CommandBase.h"
class LAC:public CommandBase
{
public:
    LAC(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
