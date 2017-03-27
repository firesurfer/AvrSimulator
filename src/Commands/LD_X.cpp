#include "LD_X.h"

LD_X::LD_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001100;
    commandMask = 0b1111111000001100;
    numArgs = 1;
    commandSize = 1;
    name = "LD_X";
}

uint64_t LD_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t ld_x = (instruction) & 0b00000011;
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t x_reg = data_memory->getXReg();
    switch(ld_x)
    {
    case 0b00:
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Unchanged
        break;
    case 0b01:
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Post increment
        x_reg++;
        break;
    case 0b10:
        x_reg--;
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Pre decrement
        break;
    }
    data_memory->setXReg(x_reg);


    ProgramCounter = ProgramCounter+1;
    return 2;
}
