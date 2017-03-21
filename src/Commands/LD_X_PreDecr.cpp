#include "LD_X_PreDecr.h"

LD_X_PreDecr::LD_X_PreDecr(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t LD_X_PreDecr::GetCommand()
{

}

uint16_t LD_X_PreDecr::NumberOfArguments()
{

}

uint16_t LD_X_PreDecr::CommandSize()
{

}

uint64_t LD_X_PreDecr::Execute(uint16_t instruction, std::vector<uint8_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    return ProgramCounter+1;
}
