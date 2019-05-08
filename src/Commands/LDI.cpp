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

#include "LDI.h"

LDI::LDI(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1110000000000000;
    commandMask = 0b1111000000000000;
    numArgs = 2;
    commandSize = 1;
    name = "LDI";
}

uint32_t LDI::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t constant = (instruction & 0xF)| ((instruction & 0x0F00) >> 4);
    uint8_t reg = (instruction & 0x00F0) >> 4;
    data_memory->setRegister(reg+16, constant);
    ProgramCounter+=1;
    return 1;
 }
