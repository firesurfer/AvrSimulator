#include "RCALL.h"

RCALL::RCALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1101000000000000;
    commandMask = 0xF000;
    numArgs = 1;
    commandSize = 1;
}

uint64_t RCALL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t address = instruction & ~commandMask;
    uint8_t low_byte = (uint8_t)ProgramCounter+1;
    uint8_t high_byte = (uint8_t)(ProgramCounter+2 >> 1);

    data_memory->pushStack(low_byte);
    data_memory->pushStack(high_byte);
    ProgramCounter+= address+1;
    return 3;
}
