#include "LAS.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

LAS::LAS(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "LAS";
}

uint32_t LAS::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    ProgramCounter += 1;
    return 1;
}
