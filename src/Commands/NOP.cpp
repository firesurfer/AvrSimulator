#include "NOP.h"

NOP::NOP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{

}

uint16_t NOP::GetCommand()
{
    return 0;
}

uint16_t NOP::NumberOfArguments()
{
    return 0;
}

uint16_t NOP::CommandSize()
{
    return 2;
}

uint16_t NOP::CommandMask()
{
    return 0b1111111111111111;
}

uint64_t NOP::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    ProgramCounter++;
}
