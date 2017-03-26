#include "DEC.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

DEC::DEC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001010;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t DEC::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd = subtractionFlags(Rd,1,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z);

    ProgramCounter += 1;
    return 1;
}
