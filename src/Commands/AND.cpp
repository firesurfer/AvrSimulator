#include "AND.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

AND::AND(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0010000000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t AND::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint32_t addrRr = (instruction&0x0F)|((instruction>>5)&0x10);
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rr = data_memory->getRegister(addrRr);
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd &= Rr;
    sreg = simpleFlags(Rd);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z);

    ProgramCounter += 1;
    return 1;
}
