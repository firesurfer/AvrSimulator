/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
        sreg = MASK_T;
    data_memory->setSREG(sreg,MASK_T);

    ProgramCounter += 1;
    return 1;
}
