#include "LDD_Z.h"

LDD_Z::LDD_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000000000;
    commandMask = 0b1101001000001000;
    numArgs = 2;
    commandSize = 1;
}

uint64_t LDD_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t offset = (instruction&0x07)|((instruction&0x0C00)>>7)|((instruction&0x2000)>>8);
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setRegister(reg,data_memory->getSRAM(z_reg+offset));

    ProgramCounter += 1;
    return 2;
}