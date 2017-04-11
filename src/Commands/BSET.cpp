#include "BSET.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

BSET::BSET(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001000;
    commandMask = 0b1111111110001111;
    numArgs = 1;
    commandSize = 1;
    name = "BSET";
}

uint32_t BSET::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t bit = (instruction>>4)&0x07;

    data_memory->setSREG(1<<bit);

    ProgramCounter += 1;
    return 1;
}
