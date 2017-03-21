#include "LDS_SRAM.h"

LDS_SRAM::LDS_SRAM(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LDS_SRAM::GetCommand()
{
    return 0b1010000000000000;
}

uint16_t LDS_SRAM::NumberOfArguments()
{
    return 2;
}

uint16_t LDS_SRAM::CommandSize()
{
    return 2;
}

uint16_t LDS_SRAM::CommandMask()
{
    return 0b1111100000000000;
}

uint64_t LDS_SRAM::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{

    return ProgramCounter+1;
}
