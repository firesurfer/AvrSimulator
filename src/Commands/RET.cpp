#include "RET.h"

RET::RET(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010100001000;
    commandMask = 0xFF;
    numArgs = 0;
    commandSize = 1;
}

uint64_t RET::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t high_byte = data_memory->popStack();
    uint8_t low_byte = data_memory->popStack();

    uint16_t address = low_byte | (high_byte<<8);
    ProgramCounter = address;
    return 4;
}
