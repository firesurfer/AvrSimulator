#include "CPSE.h"

CPSE::CPSE(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001000000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "CPSE";
}

uint32_t CPSE::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint32_t addrRr = (instruction&0x0F)|((instruction>>5)&0x10);
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rr = data_memory->getRegister(addrRr);
    uint8_t Rd = data_memory->getRegister(addrRd);
    if(Rr==Rd)
    {
        flags.skipNextInstruction = true;
    }
    ProgramCounter+=1;
    return 1;
}
