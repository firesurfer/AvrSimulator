#pragma once
#include "CommandBase.h"
class BST:public CommandBase
{
public:
    BST(MemoryMapper* _dataMemory);
    virtual uint64_t Execute(uint16_t instruction, uint16_t &ProgramCounter);
};
