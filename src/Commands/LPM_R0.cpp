#include "LPM_R0.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

LPM_R0::LPM_R0(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010111001000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "LMP_R0";
}

uint64_t LPM_R0::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    UNUSED(instruction);
    uint16_t address = data_memory->getZReg();
    if(address&0x01)
        data_memory->setRegister(R0, data_memory->getProgramMemory()->Get(address>>1)>>8);
    else
        data_memory->setRegister(R0, data_memory->getProgramMemory()->Get(address>>1));
    ProgramCounter += 1;
    return 3;
}
