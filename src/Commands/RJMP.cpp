#include "RJMP.h"

RJMP::RJMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1100000000000000;
    numArgs = 1;
    commandSize = 1;
    commandMask = 0b1111000000000000;
}

uint64_t RJMP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    int16_t offset = ((instruction & ~CommandMask()) << 4)  ;
    offset /= 16;


    ProgramCounter = ProgramCounter + offset +1 ;
    return 1;
}
