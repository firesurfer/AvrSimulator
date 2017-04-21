#include "SWAP.h"

SWAP::SWAP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000010;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 1;
    name = "SWAP";
}

uint32_t SWAP::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & !commandMask) >> 4;
    uint8_t value = data_memory->getRegister(reg);
    uint8_t lownibble = value & 0b00001111;
    uint8_t highnibble = value & 0b11110000;
    value = highnibble >> 4 | lownibble << 4;
    data_memory->setData(reg,value);
    return ProgramCounter+1;
}
