#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
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

uint64_t LDS_MEM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    return ProgramCounter+1;
}
