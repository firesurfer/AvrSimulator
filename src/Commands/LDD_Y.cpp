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

#include "LDD_Y.h"

LDD_Y::LDD_Y(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1000000000001000;
    commandMask = 0b1101001000001000;
    numArgs = 2;
    commandSize = 1;
    name = "LDD_Y";
}

uint32_t LDD_Y::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint16_t offset = (instruction&0x07)|((instruction&0x0C00)>>7)|((instruction&0x2000)>>8);
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setRegister(reg,data_memory->getData(y_reg+offset));

    ProgramCounter += 1;
    return 2;
}
