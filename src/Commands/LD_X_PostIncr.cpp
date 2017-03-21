#include "LD_X_PostIncr.h"

LD_X_PostIncr::LD_X_PostIncr(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LD_X_PostIncr::GetCommand()
{
    return 0b1001000000001101;
}

uint16_t LD_X_PostIncr::NumberOfArguments()
{
    1;
}

uint16_t LD_X_PostIncr::CommandSize()
{
    2;
}

uint16_t LD_X_PostIncr::CommandMask()
{
    return 0b1111111000001111;
}

uint64_t LD_X_PostIncr::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
