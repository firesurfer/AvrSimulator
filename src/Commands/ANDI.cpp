#include "ANDI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

ANDI::ANDI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0111000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t ANDI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t operand = (instruction&0x0F)|((instruction>>4)&0xF0);
    uint32_t addrRd = 16 + (instruction>>4)&0xF;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd &= operand;
    sreg = simpleFlags(Rd);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z);

    ProgramCounter += 1;
    return 1;
}
