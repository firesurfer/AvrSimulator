#include "JMP.h"

JMP::JMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 2;
}

uint64_t JMP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t address = this->data_memory->getProgramMemory()->Get(ProgramCounter+1);
    //TODO implement checks?
    ProgramCounter =address;

    return 3;
}
