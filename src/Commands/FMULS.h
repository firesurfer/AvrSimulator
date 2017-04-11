#pragma once
#include "CommandBase.h"
class FMULS:public CommandBase
{
public:
    FMULS(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
