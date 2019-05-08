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

#include "STD_Z.h"

STD_Z::STD_Z(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000001000000000;
    commandMask = 0b1101001000001000;
    numArgs = 2;
    commandSize = 1;
    name = "STD_Z";
}

uint32_t STD_Z::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint16_t offset = (instruction&0x07)|((instruction&0x0C00)>>7)|((instruction&0x2000)>>8);
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t z_reg = data_memory->getZReg();
    data_memory->setData(z_reg+offset,data_memory->getRegister(reg));

    ProgramCounter += 1;
    return 2;
}
