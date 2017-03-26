#include "POP.h"

POP::POP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001111;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t POP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction&!commandMask)>>4;
    data_memory->setRegister(reg,data_memory->popStack());
    ProgramCounter = ProgramCounter+1;
    return 1;
}
