#include "CommandBase.h"

CommandBase::CommandBase(MemoryMapper *_dataMemory)
{
    this->data_memory = _dataMemory;
}

uint16_t CommandBase::GetCommand()
{
    return 0;
}

uint16_t CommandBase::NumberOfArguments()
{
    return 0;
}

uint16_t CommandBase::CommandSize()
{
    return 0;
}

uint16_t CommandBase::CommandMask()
{

}

uint64_t CommandBase::Execute(uint16_t instruction, uint16_t ProgramCounter)
{
    return 0;
}
