#include "ICALL.h"

ICALL::ICALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010100001001;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "ICALL";
}

uint64_t ICALL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t dest = data_memory->getZReg();
    uint8_t low_byte = (uint8_t)ProgramCounter+1;
    uint8_t high_byte = (uint8_t)((ProgramCounter+1) >> 8);


    data_memory->pushStack(low_byte);
    data_memory->pushStack(high_byte);
    ProgramCounter = dest;
    return 3;
}
