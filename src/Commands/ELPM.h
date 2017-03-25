#pragma once
#include "CommandBase.h"
class ELPM:public CommandBase
{
public:
    ELPM(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
