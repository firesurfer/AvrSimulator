#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <cstdint>
#include "MemoryMapper.h"
#include <vector>
#include "ProcessorDefines.h"
#include "BitHelpers.h"
class CommandBase
{
public:
    CommandBase(MemoryMapper* _dataMemory);
    virtual uint16_t GetCommand();
    virtual uint16_t NumberOfArguments();
    virtual uint16_t CommandSize();
    virtual uint16_t CommandMask();
    virtual uint64_t Execute(uint16_t instruction,uint16_t &ProgramCounter);

protected :
    MemoryMapper* data_memory;
};

#endif // COMMANDBASE_H
