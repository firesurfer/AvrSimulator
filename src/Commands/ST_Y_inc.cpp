#include "ST_Y_inc.h"

ST_Y_inc::ST_Y_inc(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_Y_inc";
}

uint64_t ST_Y_inc::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setSRAM(y_reg,data_memory->getRegister(reg));
    //Post increment
    y_reg++;
    data_memory->setYReg(y_reg);

    ProgramCounter += 1;
    return 2;
}
