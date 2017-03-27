#include "NOP.h"

NOP::NOP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0;
    numArgs = 0;
    commandSize = 1;
    commandMask = 0b1111111111111111;
    name = "NOP";
}

uint64_t NOP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    ProgramCounter++;
}
