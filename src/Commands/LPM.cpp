#include "LPM.h"

LPM::LPM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000100;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 1;
}

uint64_t LPM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t address = data_memory->getZReg();
    uint8_t reg = (instruction & (0b0000000111110000))>>4;
    data_memory->setRegister(reg, data_memory->getProgramMemory()->Get(address));
    ProgramCounter = ProgramCounter +1;
    return 3;
}
