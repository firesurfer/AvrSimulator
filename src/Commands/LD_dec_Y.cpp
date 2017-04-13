#include "LD_dec_Y.h"

LD_dec_Y::LD_dec_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001010;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_dec_Y";
}

uint32_t LD_dec_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    y_reg -= 1;
    data_memory->setRegister(reg,data_memory->getData(y_reg));
    data_memory->setYReg(y_reg);

    ProgramCounter = ProgramCounter+1;
    return 2;
}
