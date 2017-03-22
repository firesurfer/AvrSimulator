#include "SBI.h"

SBI::SBI(DataMemory *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t SBI::GetCommand()
{
    return 0b1001101000000000;
}

uint16_t SBI::NumberOfArguments()
{
    return 2;
}

uint16_t SBI::CommandSize()
{
    return 2;
}

uint16_t SBI::CommandMask()
{
    return 0b1111111100000000;
}

uint64_t SBI::Execute(uint16_t instruction, std::vector<uint16_t> additionalWords, std::vector<uint8_t> &Registers, std::vector<uint8_t> &SpecialRegisters, uint16_t ProgramCounter, uint16_t &StackPointer)
{
    uint16_t addresses = instruction & ~CommandMask();
    uint8_t ioregister = (addresses & 0b0000000011111000)>>3;
    uint8_t bit = (uint8_t)(addresses & 0b0000000000000111)>>8;

    return ProgramCounter+1;
}
