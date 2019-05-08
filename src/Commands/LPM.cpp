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

#include "LPM.h"

LPM::LPM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000000100;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 1;
    name = "LPM";
}

uint32_t LPM::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint16_t address = data_memory->getZReg();
    uint8_t reg = (instruction & (0b0000000111110000))>>4;
    if(address&0x01)
        data_memory->setRegister(reg, data_memory->getProgramMemory()->Get(address>>1)>>8);
    else
        data_memory->setRegister(reg, data_memory->getProgramMemory()->Get(address>>1));

    if(instruction&0x01)
        data_memory->setZReg(address+1);

    ProgramCounter += 1;
    return 3;
}
