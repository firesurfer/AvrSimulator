#include "ST_dec_Z.h"

ST_dec_Z::ST_dec_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000000010;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_dec_Z";
}

uint32_t ST_dec_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    z_reg--;
    data_memory->setData(z_reg,data_memory->getRegister(reg));
    data_memory->setZReg(z_reg);

    ProgramCounter += 1;
    return 2;
}
