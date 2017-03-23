#include "JMP.h"

JMP::JMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
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

uint16_t JMP::CommandMask()
{
    return 0b1111111000001110;
}

uint64_t JMP::Execute(uint16_t instruction, uint16_t ProgramCounter)
{
    //uint16_t address = additionalWords[0];

   // return address;
}
