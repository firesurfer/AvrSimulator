#include "LD_Y_inc.h"

LD_Y_inc::LD_Y_inc(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_Y_inc";
}

uint64_t LD_Y_inc::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setRegister(reg,data_memory->getSRAM(y_reg));
    y_reg += 1;
    data_memory->setYReg(y_reg);

    ProgramCounter = ProgramCounter+1;
    return 2;
}
