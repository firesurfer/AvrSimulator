#include "COM.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

COM::COM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000000;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "COM";
}

uint32_t COM::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd = additionFlags(0xFF,-Rd,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z|SREG_C);

    ProgramCounter += 1;
    return 1;
}
