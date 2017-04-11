#pragma once
#include "CommandBase.h"
class LDD_Z:public CommandBase
{
public:
    LDD_Z(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
