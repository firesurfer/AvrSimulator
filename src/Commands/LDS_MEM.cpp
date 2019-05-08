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

#include "LDS_MEM.h"

LDS_MEM::LDS_MEM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000000;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 2;
    name = "LDS";
}

uint32_t LDS_MEM::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;
    uint16_t address = data_memory->getProgramMemory()->get(ProgramCounter+1);
    data_memory->setRegister(reg,data_memory->getData(address));
    ProgramCounter = ProgramCounter+2;
    return 2;
}
