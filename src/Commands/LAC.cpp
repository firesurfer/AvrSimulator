#include "LAC.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

LAC::LAC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "LAC";
}

uint32_t LAC::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    ProgramCounter += 1;
    return 1;
}
