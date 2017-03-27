#include "STS.h"

STS::STS(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000000000;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 2;
    name = "STS";
}

uint64_t STS::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t reg = (instruction>>4) & 0x1F;
    uint16_t address = data_memory->getProgramMemory()->Get(ProgramCounter+1);
    data_memory->setSRAM(address,data_memory->getRegister(reg));
    ProgramCounter = ProgramCounter+2;
    return 2;
}
