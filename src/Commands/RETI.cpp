#include "RETI.h"

RETI::RETI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010100011000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "RETI";
}

uint32_t RETI::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t high_byte = data_memory->popStack();
    uint8_t low_byte = data_memory->popStack();

    uint16_t address = (uint16_t)low_byte | ((uint16_t)high_byte<<8);
    data_memory->setSREG(MASK_I,MASK_I);
    LOG(Debug) << "RETI: Address: 0x"<<std::hex<< address << std::endl;

    ProgramCounter = address;
    return 4;
}
