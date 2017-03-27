#include "ST_Z.h"

ST_Z::ST_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000000000;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ST_Z";
}

uint64_t ST_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setSRAM(z_reg,data_memory->getRegister(reg));

    ProgramCounter += 1;
    return 2;
}
