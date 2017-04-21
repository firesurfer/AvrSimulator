#include "SBRC.h"

SBRC::SBRC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1111111000000000;
    commandMask = 0b1111111000001000;
    numArgs = 2;
    commandSize = 1;
    name = "SBRC";
}

uint32_t SBRC::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0x1F0) >> 4;
    uint8_t bit = (instruction & 0x7);
    if(!BIT_SET(data_memory->getRegister(reg),bit))
    {
        flags.skipNextInstruction = true;
    }
    ProgramCounter+=1;
    return 1;
}
