#include "LD_X_PostIncr.h"

LD_X_PostIncr::LD_X_PostIncr(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LD_X_PostIncr::GetCommand()
{

}

uint16_t LD_X_PostIncr::NumberOfArguments()
{

}

uint16_t LD_X_PostIncr::CommandSize()
{

}

uint64_t LD_X_PostIncr::Execute(uint16_t instruction, std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
