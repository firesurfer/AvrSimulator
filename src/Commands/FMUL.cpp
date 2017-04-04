#include "FMUL.h"

FMUL::FMUL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0000001100001000;
    commandMask = 0xFF88;
    numArgs = 2;
    commandSize = 1;
    name = "FMUL";
}

uint64_t FMUL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg1 = (instruction & 0x7) + 16;
    uint8_t reg2 = (instruction & 0x70) +16;
    uint16_t result = data_memory->getRegister(reg1) * data_memory->getRegister(reg2);

    uint8_t sreg = data_memory->getSREG();
    if(BIT_SET(result, 15))
        SET_BIT(sreg, SREG_C);
    else
        CLR_BIT(sreg,SREG_C);

    if(result == 0)
        SET_BIT(sreg, SREG_Z);
    else
        CLR_BIT(sreg, SREG_Z);

    data_memory->setSREG(sreg);
    uint8_t high_byte = (uint8_t)(result >>8);
    uint8_t low_byte = (uint8_t) result;
    data_memory->setRegister(R0+1,high_byte);
    data_memory->setRegister(R0, low_byte);

    ProgramCounter+=1;
    return 2;
}
