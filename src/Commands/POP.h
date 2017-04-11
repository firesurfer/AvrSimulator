#pragma once
#include "CommandBase.h"
class POP:public CommandBase
{
public:
    POP(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
