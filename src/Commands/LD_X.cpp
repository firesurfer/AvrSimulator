#include "LD_X.h"

LD_X::LD_X(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LD_X::GetCommand()
{
    return 0b1001000000001100;
}

uint16_t LD_X::NumberOfArguments()
{

}

uint16_t LD_X::CommandSize()
{

}

uint16_t LD_X::CommandMask()
{
    return 0b1111111000001111;
}

uint64_t LD_X::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
