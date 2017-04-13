#include "BRBS.h"

BRBS::BRBS(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1111000000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "BRBS";
}

uint32_t BRBS::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t bit = instruction&0x07;
    int16_t offset = (instruction&0x3F8)<<6;
    offset = offset/512+1;
    uint8_t sreg = data_memory->getSREG(1<<bit);
    if(sreg){
        ProgramCounter += offset;
        return 2;
    }else{
        ProgramCounter += 1;
        return 1;
    }
}
