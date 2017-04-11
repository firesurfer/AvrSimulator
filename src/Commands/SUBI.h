#pragma once
#include "CommandBase.h"
class SUBI:public CommandBase
{
public:
    SUBI(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};
