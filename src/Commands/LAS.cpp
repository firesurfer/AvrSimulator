#include "LAS.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

LAS::LAS(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000101;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 1;
    name = "LAS";
}

uint32_t LAS::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0x1F0) >> 4;
    uint8_t regData = data_memory->getRegister(reg);
    uint16_t address = data_memory->getZReg();
    uint8_t data = data_memory->getData(address);
    data |= regData;
    data_memory->setData(address,data);
    data_memory->setRegister(reg,data);
    ProgramCounter += 1;
    return 2;
}
