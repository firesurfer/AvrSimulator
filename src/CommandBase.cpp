#include "CommandBase.h"

CommandBase::CommandBase(DataMemory *_dataMemory)
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

uint64_t CommandBase::Execute(uint16_t instruction, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return 0;
}
