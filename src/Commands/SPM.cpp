#include "SPM.h"

SPM::SPM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010111101000;
    commandMask = 0xFFFF;
    numArgs = 2;
    commandSize = 1;
}

uint64_t SPM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t high_byte = data_memory->getRegister(R0+1);
    uint8_t low_byte = data_memory->getRegister(R0);
    uint16_t data = low_byte | (high_byte <<8);
    uint16_t address = data_memory->getZReg();
    data_memory->getProgramMemory()->Set(address,data);
    ProgramCounter+=1;
    return 2;//TODO
}
