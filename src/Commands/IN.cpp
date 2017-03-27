#include "IN.h"

IN::IN(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1011000000000000;
    commandMask = 0b1111100000000000;
    numArgs = 2;
    commandSize = 1;
    name = "IN";
}

uint64_t IN::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t ioreg  = instruction &0xF | ((instruction & 0b0000011000000000) >> 5);
    uint8_t reg = (instruction & (0b0000000111110000))>>4;
    data_memory->setRegister(reg, data_memory->getIORegister(ioreg));
    ProgramCounter = ProgramCounter+1;
    return 1;
}
