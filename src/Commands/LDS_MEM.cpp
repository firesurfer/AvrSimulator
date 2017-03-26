#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000000;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 2;
}

uint64_t LDS_MEM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;
    uint16_t address = data_memory->getProgramMemory()->Get(ProgramCounter+1);
    data_memory->setRegister(reg,data_memory->getSRAM(address));
    ProgramCounter = ProgramCounter+2;
    return 2;
}
