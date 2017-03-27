#include "BRBC.h"

BRBC::BRBC(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1111010000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "BRBC";
}

uint64_t BRBC::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint8_t bit = instruction&0x07;
    int16_t offset = instruction<<6;
    offset = offset/512+1;
    uint8_t sreg = data_memory->getSREG(1<<bit);
    if(!sreg){
        ProgramCounter += offset;
        return 2;
    }else{
        ProgramCounter += 1;
        return 1;
    }
}
