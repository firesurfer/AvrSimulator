#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <cstdint>
#include "DataMemory.h"
#include <vector>
#include "ProcessorDefines.h"
#include "BitHelpers.h"
class CommandBase
{
public:
    CommandBase(DataMemory* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
    virtual uint16_t CommandMask();
    virtual uint64_t Execute(uint16_t instruction,std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t>& SpecialRegisters,uint16_t ProgramCounter, uint16_t& StackPointer);

protected :
    DataMemory* data_memory;
};

#endif // COMMANDBASE_H
