#include "LDS_SRAM.h"

LDS_SRAM::LDS_SRAM(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LDS_SRAM::GetCommand()
{

}

uint16_t LDS_SRAM::NumberOfArguments()
{

}

uint16_t LDS_SRAM::CommandSize()
{

}

uint64_t LDS_SRAM::Execute(uint16_t instruction, std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
