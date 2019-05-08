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

#include "MOVW.h"

MOVW::MOVW(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0000000100000000;
    commandMask = 0xFF00;
    numArgs = 2;
    commandSize = 1;
    name = "MOVW";
}

uint32_t MOVW::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t src = (instruction & 0xF);
    uint8_t dest = (instruction & 0xF0) >> 4;
    data_memory->setRegister(dest*2,data_memory->getRegister(src*2));
    data_memory->setRegister(dest*2+1,data_memory->getRegister(src*2+1));
    ProgramCounter+=1;
    return 1;
}
