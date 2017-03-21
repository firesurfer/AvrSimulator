#pragma once

#include "CommandBase.h"
class LDS_SRAM : public CommandBase
{
public:
    LDS_SRAM(DataMemory* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
    virtual uint16_t CommandMask();
    virtual uint64_t Execute(uint16_t instruction,std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t>& SpecialRegisters,uint16_t ProgramCounter, uint16_t& StackPointer);
};

