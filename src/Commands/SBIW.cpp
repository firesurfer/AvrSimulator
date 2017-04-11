#include "SBIW.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

SBIW::SBIW(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001011100000000;
    commandMask = 0b1111111100000000;
    numArgs = 2;
    commandSize = 1;
    name = "SBIW";
}

uint32_t SBIW::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint16_t summand = (instruction&0x0F)|((instruction>>2)&0x30);
    uint32_t addrRd = 24 + ((instruction>>3)&0x06);
    uint8_t Rdl = data_memory->getRegister(addrRd);
    uint8_t Rdh = data_memory->getRegister(addrRd+1);
    uint8_t sreg = 0;

    Rdl = subtractionFlags(Rdl,summand,sreg);
    Rdh = subtractionFlags(Rdh,0,sreg);
    data_memory->setRegister(addrRd,Rdl);
    data_memory->setRegister(addrRd+1,Rdh);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z|MASK_C);

    ProgramCounter += 1;
    return 2;
}
