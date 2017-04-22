#include "WDR.h"

WDR::WDR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010110101000;
    commandMask = 0xFFFF;
    numArgs = 2;
    commandSize = 1;
    name = "WDR";
}

uint32_t WDR::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    LOG(Info) << "Watchdog reset" << std::endl;
    ProgramCounter += 1;
    return 1;
}
