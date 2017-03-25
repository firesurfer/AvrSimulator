#pragma once
#include "CommandBase.h"
class ASR:public CommandBase
{
public:
    ASR(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
