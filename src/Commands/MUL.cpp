#include "MUL.h"

MUL::MUL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001110000000000;
    commandMask = 0xFC00;
    numArgs = 2;
    commandSize = 1;
    name = "MUL";
}

uint64_t MUL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg1 = (instruction & 0xF) | ((instruction & 0x200) >> 5);
    uint8_t reg2 = (instruction & 0x1F0)>>4;
    uint16_t result = data_memory->getRegister(reg1) * data_memory->getRegister(reg2);
    uint8_t sreg = data_memory->getSREG();
    if(BIT_SET(result,15))
        sreg |= (1<<SREG_C);
    if(result == 0)
        sreg |= (1<<SREG_Z);
    data_memory->setSREG(sreg);
    uint8_t high_byte = (uint8_t)(result >>8);
    uint8_t low_byte = (uint8_t) result;
    data_memory->setRegister(R0+1,high_byte);
    data_memory->setRegister(R0, low_byte);
    ProgramCounter+=1;
    return 2;
}
