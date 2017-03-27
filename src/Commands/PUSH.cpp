#include "PUSH.h"

PUSH::PUSH(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001111;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 1;
    name = "PUSH";
}

uint64_t PUSH::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{

    uint8_t reg = (instruction>>4) & 0x1F;
    data_memory->pushStack(data_memory->getRegister(reg));
    ProgramCounter= ProgramCounter+1;
    return 2;
}
