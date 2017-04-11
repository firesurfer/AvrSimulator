#include "BST.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

BST::BST(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1111101000000000;
    commandMask = 0b1111111000001000;
    numArgs = 2;
    commandSize = 1;
    name = "BST";
}

uint32_t BST::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t bit = instruction&0x07;
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;
    if(bit_set(Rd,bit))
        sreg = 0xFF;
    data_memory->setSREG(sreg,MASK_T);

    ProgramCounter += 1;
    return 1;
}
