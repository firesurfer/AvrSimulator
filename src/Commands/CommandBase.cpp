#include "CommandBase.h"

CommandBase::CommandBase(MemoryMapper *_dataMemory)
{
    this->data_memory = _dataMemory;
    command = 0;
    commandMask = 0;
    commandSize = 0;
    numArgs = 0;
    name = "CommandBase";
}

uint16_t CommandBase::GetCommand() const
{
    return command;
}

uint16_t CommandBase::NumberOfArguments() const
{
    return numArgs;
}

uint16_t CommandBase::CommandSize() const
{
    return commandSize;
}

uint16_t CommandBase::CommandMask() const
{
    return commandMask;
}

uint32_t CommandBase::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    return 0;
}

std::string CommandBase::Name() const
{
    return name;
}
