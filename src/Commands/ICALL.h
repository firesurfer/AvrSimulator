#pragma once
#include "CommandBase.h"
class ICALL:public CommandBase
{
public:
    ICALL(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
