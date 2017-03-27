#include "BCLR.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

BCLR::BCLR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010010001000;
    commandMask = 0b1111111110001111;
    numArgs = 1;
    commandSize = 1;
    name = "BCLR";
}

uint64_t BCLR::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t bit = (instruction>>4)&0x07;

    data_memory->setSREG(0,1<<bit);

    ProgramCounter += 1;
    return 1;
}
