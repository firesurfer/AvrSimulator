#include "RJMP.h"

RJMP::RJMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t RJMP::GetCommand()
{
    return 0b1100000000000000;
}

uint16_t RJMP::NumberOfArguments()
{
    return 2;
}

uint16_t RJMP::CommandSize()
{
    return 4;
}

uint16_t RJMP::CommandMask()
{
    return 0b1111000000000000;
}

uint64_t RJMP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    int16_t offset = ((instruction & ~CommandMask()) << 4)  ;
    offset /= 16;


    ProgramCounter = ProgramCounter + offset +1 ;
    return 1;
}
