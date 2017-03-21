#include "JMP.h"

JMP::JMP(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t JMP::GetCommand()
{
    return 0b0001110000000000;
}

uint16_t JMP::NumberOfArguments()
{
    return 2;
}

uint16_t JMP::CommandSize()
{
    return 4;
}

uint64_t JMP::Execute(uint16_t instruction, std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{

    return ProgramCounter+1;
}
