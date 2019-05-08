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

#include "NEG.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

NEG::NEG(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "NEG";
}

uint32_t NEG::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd = subtractionFlags(0,Rd,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_H|MASK_S|MASK_V|MASK_N|MASK_Z|SREG_C);

    ProgramCounter += 1;
    return 1;
}
