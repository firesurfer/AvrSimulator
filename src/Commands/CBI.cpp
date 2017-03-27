#include "CBI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

CBI::CBI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001100000000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
}

uint64_t CBI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{

    ProgramCounter += 1;
    return 2;
}
