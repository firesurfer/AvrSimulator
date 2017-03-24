#include "LD_X.h"

LD_X::LD_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001100;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
