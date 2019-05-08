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

#include "BCLR.h"
#include "FlagCalculator.h"
#include "BitHelpers.h"

using namespace FlagCalculator;
using namespace BitHelpers;

BCLR::BCLR(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010010001000;
    commandMask = 0b1111111110001111;
    numArgs = 1;
    commandSize = 1;
    name = "BCLR";
}

uint32_t BCLR::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t bit = (instruction>>4)&0x07;

    data_memory->setSREG(0,1<<bit);

    ProgramCounter += 1;
    return 1;
}
