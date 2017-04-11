#include "OUT.h"

OUT::OUT(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1011100000000000;
    commandMask = 0b1111100000000000;
    numArgs = 0;
    commandSize = 1;
    name = "OUT";
}

uint32_t OUT::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0b0000000111110000) >>4;
    uint8_t ioreg = (instruction & 0xF) | ((instruction & 0x0600)>>5);
    data_memory->setIORegister(ioreg, data_memory->getRegister(reg));
    ProgramCounter+=1;
    return 1;
}
