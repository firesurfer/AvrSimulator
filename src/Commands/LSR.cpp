#include "LSR.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

LSR::LSR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000110;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LSR::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    if(Rd&0x01)
        set_bit(sreg,SREG_C);
    else
        clear_bit(sreg,SREG_C);
    Rd>>=1;
    sreg=shiftFlags(Rd,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z|SREG_C);

    ProgramCounter += 1;
    return 1;
}
