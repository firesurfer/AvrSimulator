#pragma once
#include "CommandBase.h"
class SBIW:public CommandBase
{
public:
    SBIW(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
