#include "ST_X.h"

ST_X::ST_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001100;
    commandMask = 0b1111111000001100;
    numArgs = 1;
    commandSize = 1;
}

uint64_t ST_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t ld_x = (instruction) & 0b00000011;
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t x_reg = data_memory->getXReg();
    switch(ld_x)
    {
    case 0b00:
        data_memory->setSRAM(x_reg,data_memory->getRegister(reg));
        //Unchanged
        break;
    case 0b01:
        data_memory->setSRAM(x_reg,data_memory->getRegister(reg));
        //Post increment
        x_reg++;
        break;
    case 0b10:
        x_reg--;
        data_memory->setSRAM(x_reg,data_memory->getRegister(reg));
        //Pre decrement
        break;
    }
    data_memory->setXReg(x_reg);


    ProgramCounter += 1;
    return 2;
}
