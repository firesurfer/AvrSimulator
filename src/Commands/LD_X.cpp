#include "LD_X.h"

LD_X::LD_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
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

uint64_t LD_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
