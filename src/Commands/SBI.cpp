#include "SBI.h"

SBI::SBI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001101000000000;
    numArgs = 2;
    commandSize = 1;
    commandMask = 0b1111111100000000;
}

uint64_t SBI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t addresses = instruction & ~CommandMask();
    uint8_t ioregister = (addresses & 0b0000000011111000)>>3;
    uint8_t bit = (uint8_t)(addresses & 0b0000000000000111)>>8;
    data_memory->setIORegister(ioregister,data_memory->getIORegister(ioregister)|bit);
    ProgramCounter = ProgramCounter+1;
    return 2;
}
