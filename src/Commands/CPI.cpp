#include "CPI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

CPI::CPI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0011000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t CPI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t operand = (instruction&0x0F)|((instruction>>4)&0xF0);
    uint32_t addrRd = 16 + (instruction>>4)&0xF;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    additionFlags(Rd,-operand,sreg);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z);

    ProgramCounter += 1;
    return 1;
}
