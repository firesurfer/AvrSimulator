#include "PUSH.h"

PUSH::PUSH(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001111;
    commandMask = 0b111111000001111;
    numArgs = 2;
    commandSize = 1;
}

uint64_t PUSH::Execute(uint16_t instruction, uint16_t &ProgramCounter)
{
    uint16_t stack_ptr = data_memory->getStackPtr();
    uint8_t reg = (instruction & !commandMask) >> 4;
    data_memory->setSRAM(stack_ptr,data_memory->getSRAM(reg));
    stack_ptr++;
    data_memory->setStackPtr(stack_ptr);

    ProgramCounter= ProgramCounter+1;
}
