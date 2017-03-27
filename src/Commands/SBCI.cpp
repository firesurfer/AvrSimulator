#include "SBCI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

SBCI::SBCI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0100000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
    name = "SBCI";
}

uint64_t SBCI::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t operand = (instruction&0x0F)|((instruction>>4)&0xF0);
    uint32_t addrRd = 16 + ((instruction>>4)&0xF);
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = data_memory->getSREG(MASK_C|MASK_Z);

    Rd = subtractionFlags(Rd,operand,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_H|MASK_S|MASK_V|MASK_N|MASK_Z|MASK_C);

    ProgramCounter += 1;
    return 1;
}
