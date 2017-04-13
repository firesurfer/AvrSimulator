#include "SBC.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

SBC::SBC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0000100000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "SBC";
}

uint32_t SBC::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint32_t addrRr = (instruction&0x0F)|((instruction>>5)&0x10);
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rr = data_memory->getRegister(addrRr);
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = data_memory->getSREG(MASK_C|MASK_Z);

    Rd = subtractionFlags(Rd,Rr,sreg,true);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_H|MASK_S|MASK_V|MASK_N|MASK_Z|MASK_C);

    ProgramCounter += 1;
    return 1;
}
