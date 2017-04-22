#include "SLEEP.h"

SLEEP::SLEEP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010110001000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "SLEEP";
}

uint32_t SLEEP::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    //HOW to fucking sleep ?
    LOG(Important) << "Sleeping for a few cycles (100)" << std::endl;

    ProgramCounter += 1;
    return 100;
}
