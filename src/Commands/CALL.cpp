#include "CALL.h"

CALL::CALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001110;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 2;
    name = "CALL";
}

uint64_t CALL::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{

    uint32_t address = data_memory->getProgramMemory()->Get(ProgramCounter+1);
    address |= uint32_t(instruction&0x0001)<<16 | uint32_t(instruction&0x01F0)<<13;

    uint8_t low_byte = (uint8_t)ProgramCounter+2;
    uint8_t high_byte = (uint8_t)((ProgramCounter+2) >> 8);
#ifdef DEBUG
    std::cout << "CALL: Address: " << std::hex<< address << std::endl;
    std::cout << "CALL: Stack:   " << std::hex << (int)low_byte << " " << (int)high_byte << std::endl;
#endif
    data_memory->pushStack(low_byte);
    data_memory->pushStack(high_byte);
    ProgramCounter = address;

    return 4;
}
