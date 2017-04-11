#pragma once
#include "CommandBase.h"
class BLD:public CommandBase
{
public:
    BLD(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
