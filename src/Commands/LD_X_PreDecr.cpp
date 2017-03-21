#include "LD_X_PreDecr.h"

LD_X_PreDecr::LD_X_PreDecr(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LD_X_PreDecr::GetCommand()
{
    return 0b1001000000001110;
}

uint16_t LD_X_PreDecr::NumberOfArguments()
{
    return 1;
}

uint16_t LD_X_PreDecr::CommandSize()
{
    return 2;
}

uint16_t LD_X_PreDecr::CommandMask()
{
    return 0b1111111000001111;
}

uint64_t LD_X_PreDecr::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
