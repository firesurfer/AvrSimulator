#include "MOV.h"

MOV::MOV(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0010110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "MOV";
}

uint32_t MOV::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t src = (instruction & 0xF) | ((instruction & 0x0200) >> 5);
    uint8_t dest = (instruction & 0x1F0) >> 4;
    data_memory->setRegister(dest,data_memory->getRegister(src));
    ProgramCounter+=1;
    return 1;
}
