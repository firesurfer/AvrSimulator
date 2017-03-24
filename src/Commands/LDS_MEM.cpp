#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000000;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 2;
}

uint64_t LDS_MEM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
