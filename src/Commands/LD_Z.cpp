#include "LD_Z.h"

LD_Z::LD_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001100;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
