#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LDS_MEM::GetCommand()
{

}

uint16_t LDS_MEM::NumberOfArguments()
{

}

uint16_t LDS_MEM::CommandSize()
{

}

uint64_t LDS_MEM::Execute(uint16_t instruction, std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
