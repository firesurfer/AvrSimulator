#include "BREAK.h"

BREAK::BREAK(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010110011000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
}

uint64_t BREAK::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{

#ifdef JTAG_ENABLED
    //TODO let some debugging happen
#else
    //We do nothing
#endif
    ProgramCounter+=1;
    return 1;
}
