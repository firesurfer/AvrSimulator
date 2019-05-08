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

#include "IN.h"

IN::IN(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1011000000000000;
    commandMask = 0b1111100000000000;
    numArgs = 2;
    commandSize = 1;
    name = "IN";
}

uint32_t IN::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t ioreg  = instruction &0xF | ((instruction & 0b0000011000000000) >> 5);
    uint8_t reg = (instruction & (0b0000000111110000))>>4;
    data_memory->setRegister(reg, data_memory->getIORegister(ioreg));
    ProgramCounter = ProgramCounter+1;
    return 1;
}
