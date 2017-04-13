#include "LD_Z_inc.h"

LD_Z_inc::LD_Z_inc(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_Z_inc";
}

uint32_t LD_Z_inc::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setRegister(reg,data_memory->getData(z_reg));
    z_reg += 1;
    data_memory->setZReg(z_reg);

    ProgramCounter = ProgramCounter+1;
    return 2;
}
