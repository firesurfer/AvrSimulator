#pragma once
#include "CommandBase.h"
class RET:public CommandBase
{
public:
    RET(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
