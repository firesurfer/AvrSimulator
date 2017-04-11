#pragma once
#include "CommandBase.h"
class LPM_R0:public CommandBase
{
public:
    LPM_R0(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
