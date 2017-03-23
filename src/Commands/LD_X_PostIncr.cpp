#include "LD_X_PostIncr.h"

LD_X_PostIncr::LD_X_PostIncr(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
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

uint64_t LD_X_PostIncr::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
