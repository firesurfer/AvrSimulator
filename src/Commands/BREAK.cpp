#include "BREAK.h"

BREAK::BREAK(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010110011000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "BREAK";
}

uint32_t BREAK::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

#ifdef JTAG_ENABLED
    //TODO let some debugging happen
#else
    //We do nothing
#endif
    LOG(Info) << "Breakpoint" << std::endl;
    ProgramCounter+=1;
    return 1;
}
