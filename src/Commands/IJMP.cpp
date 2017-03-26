#include "IJMP.h"

IJMP::IJMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001001;
    commandMask = 0xFFFF;
    numArgs = 2;
    commandSize = 1;
}

uint64_t IJMP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t address = data_memory->getZReg();
    ProgramCounter = address;
    return 2;
}
