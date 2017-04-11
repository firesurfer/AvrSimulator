#include "CBI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

CBI::CBI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001100000000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
    name = "CBI";
}

uint32_t CBI::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint16_t addresses = instruction & ~CommandMask();
    uint8_t ioregister = (addresses & 0b0000000011111000)>>3;
    uint8_t bit = (uint8_t)(addresses & 0b0000000000000111);
    data_memory->setIORegister(ioregister,data_memory->getIORegister(ioregister)&~(1<<bit));
    ProgramCounter = ProgramCounter+1;
    return 2;
}

