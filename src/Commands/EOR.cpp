#include "EOR.h"

EOR::EOR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0010010000000000;
    numArgs = 2;
    commandSize = 1;
    commandMask = 0b1111110000000000;
}

uint64_t EOR::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t high_byte = (uint8_t)(instruction >> 8);
    uint8_t low_byte = (uint8_t)(instruction);
    uint8_t dest;
    uint8_t source;
    //uint16_t address = additionalWords[0];

   // return address;
}
