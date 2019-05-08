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

#include "ORI.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

ORI::ORI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0110000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
    name = "ORI";
}

uint32_t ORI::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t operand = (instruction&0x0F)|((instruction>>4)&0xF0);
    uint32_t addrRd = 16 + ((instruction>>4)&0xF);
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    Rd |= operand;
    sreg = simpleFlags(Rd);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z);

    ProgramCounter += 1;
    return 1;
}
