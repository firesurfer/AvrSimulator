#include "BLD.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

BLD::BLD(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1111100000000000;
    commandMask = 0b1111111000001000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t BLD::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t bit = instruction&0x07;
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = data_memory->getSREG(MASK_T);
    if(sreg)
        set_bit(Rd,bit);
    else
        clear_bit(Rd,bit);
    data_memory->setRegister(addrRd,Rd);

    ProgramCounter += 1;
    return 1;
}
