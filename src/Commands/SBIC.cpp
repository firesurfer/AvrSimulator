#include "SBIC.h"

SBIC::SBIC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001100100000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
    name = "SBIC";
}

uint32_t SBIC::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0xF8) >> 3;
    uint8_t bit = (instruction & 0x7);
    if(!BIT_SET(data_memory->getIORegister(reg),bit))
    {
        flags.skipNextInstruction = true;
    }
    ProgramCounter+=1;
    return 1;
}
