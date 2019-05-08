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

#include "SBIS.h"

SBIS::SBIS(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001101100000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
    name = "SBIS";
}

uint32_t SBIS::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0xF8) >> 3;
    uint8_t bit = (instruction & 0x7);
    if(BIT_SET(data_memory->getIORegister(reg),bit))
    {
        flags.skipNextInstruction = true;
    }
    ProgramCounter+=1;
    return 1;
}
