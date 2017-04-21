#include "XCH.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

XCH::XCH(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "XCH";
}

uint32_t XCH::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    uint8_t reg = (instruction & 0x1F0) >> 4;
    uint8_t regData = data_memory->getRegister(reg);
    uint16_t address = data_memory->getZReg();
    uint8_t data = data_memory->getData(address);

    data_memory->setData(address,regData);
    data_memory->setRegister(reg,data);
    ProgramCounter += 1;
    return 1;
}
