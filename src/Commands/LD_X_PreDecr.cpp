#include "LD_X_PreDecr.h"

LD_X_PreDecr::LD_X_PreDecr(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001110;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_X_PreDecr::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
