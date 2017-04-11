#include "STD_Y.h"

STD_Y::STD_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000001000;
    commandMask = 0b1101001000001000;
    numArgs = 2;
    commandSize = 1;
    name = "STD_Y";
}

uint32_t STD_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    uint16_t offset = (instruction&0x07)|((instruction&0x0C00)>>7)|((instruction&0x2000)>>8);
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();

    data_memory->setSRAM(y_reg+offset,data_memory->getRegister(reg));

    ProgramCounter += 1;
    return 2;
}
