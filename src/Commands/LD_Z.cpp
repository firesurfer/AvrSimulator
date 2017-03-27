#include "LD_Z.h"

LD_Z::LD_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000000000000000;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_Z";
}

uint64_t LD_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setRegister(reg,data_memory->getSRAM(z_reg));

    ProgramCounter = ProgramCounter+1;
    return 2;
}
