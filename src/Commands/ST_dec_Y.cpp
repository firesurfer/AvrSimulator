#include "ST_dec_Y.h"

ST_dec_Y::ST_dec_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001010;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_dec_Y";
}

uint32_t ST_dec_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    y_reg--;
    data_memory->setData(y_reg,data_memory->getRegister(reg));
    data_memory->setYReg(y_reg);

    ProgramCounter += 1;
    return 2;
}
