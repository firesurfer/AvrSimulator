#pragma once
#include "CommandBase.h"
class SBIS:public CommandBase
{
public:
    SBIS(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
