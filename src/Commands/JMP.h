#pragma once

#include "CommandBase.h"
class JMP:public CommandBase
{
public:
    JMP(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t  instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);

};
