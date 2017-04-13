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
    uint8_t src = (instruction & 0xF);
    uint8_t dest = (instruction & 0xF0) >> 4;
    data_memory->setRegister(dest*2,data_memory->getRegister(src*2));
    data_memory->setRegister(dest*2+1,data_memory->getRegister(src*2+1));
    ProgramCounter+=1;
    return 1;
}
