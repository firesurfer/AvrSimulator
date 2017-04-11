#pragma once
#include "CommandBase.h"
class CBI:public CommandBase
{
public:
    CBI(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
