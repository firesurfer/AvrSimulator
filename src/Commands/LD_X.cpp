#include "LD_X.h"

LD_X::LD_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001100;
    commandMask = 0b1111111000001100;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LD_X::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t ld_x = (instruction) & 0b00001111;
    uint8_t reg = ((instruction) & !commandMask)>>4;
    uint16_t* x_reg_ptr = (uint16_t*)&data_memory->getDataMemory()->GetDataPtr()[X_L];
    uint16_t x_reg = *x_reg_ptr;
    BitHelpers::swap_bytes(x_reg);
    switch(ld_x)
    {
    case 0b1100:
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Unchanged
        break;
    case 0b1101:
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Post increment
        x_reg++;
        break;
    case 0b1110:
        x_reg--;
        data_memory->setRegister(reg,data_memory->getSRAM(x_reg));
        //Pre decrement
        break;
    }
    BitHelpers::swap_bytes(x_reg);
    *x_reg_ptr = x_reg;


    ProgramCounter = ProgramCounter+1;
    return 2;
}
