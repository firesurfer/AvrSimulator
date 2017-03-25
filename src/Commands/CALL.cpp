#include "CALL.h"

CALL::CALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001110;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 2;
}

uint64_t CALL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint32_t address = data_memory->getSRAM(ProgramCounter+1);
    uint16_t rest_bits = instruction & !commandMask;
    uint16_t temp = rest_bits;
    rest_bits = (rest_bits & 0b0000000111110000) >> 3;
    rest_bits |= (temp & 0b0000000000000001);
    address |= (rest_bits << 16);

    ProgramCounter = ProgramCounter+2;
}
