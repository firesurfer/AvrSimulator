#pragma once
#include "CommandBase.h"
class ADIW:public CommandBase
{
public:
    ADIW(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
