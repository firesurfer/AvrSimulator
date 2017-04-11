#include "ST_Y.h"

ST_Y::ST_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000001000;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_Y";
}

uint32_t ST_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setSRAM(y_reg,data_memory->getRegister(reg));

    ProgramCounter += 1;
    return 2;
}
