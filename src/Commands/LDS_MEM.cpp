#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LDS_MEM::GetCommand()
{
    return 0b1001000000000000;
}

uint16_t LDS_MEM::NumberOfArguments()
{
    return 2;
}

uint16_t LDS_MEM::CommandSize()
{
    return 4;
}

uint16_t LDS_MEM::CommandMask()
{
    return 0b1111111000001111;
}

uint64_t LDS_MEM::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
