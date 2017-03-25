#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <cstdint>
#include <vector>
#include "MemoryMapper.h"

#include "ProcessorDefines.h"
#include "BitHelpers.h"

class CommandBase
{
public:
    CommandBase(MemoryMapper* _dataMemory);
    virtual uint16_t GetCommand() const;
    virtual uint16_t NumberOfArguments() const;
    virtual uint16_t CommandSize() const;
    virtual uint16_t CommandMask() const;
    virtual uint64_t Execute(uint16_t instruction,uint16_t &ProgramCounter);

protected :
    MemoryMapper* data_memory;
    uint16_t command;
    uint16_t numArgs;
    uint16_t commandSize;
    uint16_t commandMask;
};

#endif // COMMANDBASE_H
