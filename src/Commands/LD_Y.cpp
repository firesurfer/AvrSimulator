#include "LD_Y.h"

LD_Y::LD_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000000000001000;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_Y";
}

uint32_t LD_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setRegister(reg,data_memory->getSRAM(y_reg));

    ProgramCounter = ProgramCounter+1;
    return 2;
}
