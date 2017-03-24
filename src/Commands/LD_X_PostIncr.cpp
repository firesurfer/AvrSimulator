#include "LD_X_PostIncr.h"

LD_X_PostIncr::LD_X_PostIncr(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001101;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_X_PostIncr::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
