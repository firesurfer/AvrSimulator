#include "LDI.h"

LDI::LDI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1110000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t LDI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t constant = (instruction & 0xF)| ((instruction & 0x0F00) >> 4);
    uint8_t reg = (instruction & 0x00F0) >> 4;
    data_memory->setRegister(reg+16, constant);
    ProgramCounter+=1;
    return 1;
 }
