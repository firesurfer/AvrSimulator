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

#include "ASR.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

ASR::ASR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000101;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "ASR";
}

uint32_t ASR::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint32_t addrRd = (instruction>>4)&0x1F;
    uint8_t Rd = data_memory->getRegister(addrRd);
    uint8_t sreg = 0;

    if(Rd&0x01)
        set_bit(sreg,SREG_C);
    else
        clear_bit(sreg,SREG_C);
    Rd = (Rd&0x80) | (Rd>>1);
    sreg = shiftFlags(Rd,sreg);
    data_memory->setRegister(addrRd,Rd);
    data_memory->setSREG(sreg,MASK_S|MASK_V|MASK_N|MASK_Z|SREG_C);

    ProgramCounter += 1;
    return 1;
}
