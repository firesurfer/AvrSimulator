#pragma once

#include "CommandBase.h"
class ST_dec_Z : public CommandBase
{
public:
    ST_dec_Z(MemoryMapper* _dataMemory);
    virtual uint32_t Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags);
};

