#include "XCH.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

XCH::XCH(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "XCH";
}

uint32_t XCH::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{


    ProgramCounter += 1;
    return 1;
}
