#include "ST_Z_inc.h"

ST_Z_inc::ST_Z_inc(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000000001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_Z_inc";
}

uint32_t ST_Z_inc::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setData(z_reg,data_memory->getRegister(reg));
    //Post increment
    z_reg++;
    data_memory->setZReg(z_reg);

    ProgramCounter += 1;
    return 2;
}
