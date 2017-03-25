#pragma once
#include "CommandBase.h"
class CALL:public CommandBase
{
public:
    CALL(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
