#include "LD_X.h"

LD_X::LD_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001100;
    commandMask = 0b1111111000001100;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t ld_x = (instruction << 8) & 0b00001111;
    uint8_t reg = ((instruction) & !commandMask)<<12;
    switch(ld_x)
    {
    case 0b1100:
        //Unchanged
        break;
    case 0b1101:
        //Post increment
        break;
    case 0b1110:
        //Pre decrement
        break;
    }

    return ProgramCounter+1;
}
