#include "LDS_SRAM.h"

LDS_SRAM::LDS_SRAM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1010000000000000;
    commandMask = 0b1111100000000000;
    numArgs = 2;
    commandSize = 1;
    ///only relevant for attiny10 based devices, can adress 128bytes SRAM from offset 0x40,
    /// may interfere with the LDD instruction
}

uint64_t LDS_SRAM::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{

    return ProgramCounter+1;
}
