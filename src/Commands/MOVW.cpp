#include "MOVW.h"

MOVW::MOVW(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0000000100000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
    name = "MOVW";
}

uint32_t MOVW::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t src = (instruction & 0xF) | ((instruction & 0x0200) >> 5);
    uint8_t dest = (instruction & 0x1F0) >> 4;
    data_memory->setRegister(dest,data_memory->getRegister(src));
    data_memory->setRegister(dest+1,data_memory->getRegister(src+1));
    ProgramCounter+=1;
    return 1;
}
