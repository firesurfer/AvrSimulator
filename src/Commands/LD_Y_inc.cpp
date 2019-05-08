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

#include "LD_Y_inc.h"

LD_Y_inc::LD_Y_inc(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001000000001001;
    commandMask = 0b1111111000001111;
    numArgs = 1;
    commandSize = 1;
    name = "LD_Y_inc";
}

uint32_t LD_Y_inc::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t y_reg = data_memory->getYReg();
    data_memory->setRegister(reg,data_memory->getData(y_reg));
    y_reg += 1;
    data_memory->setYReg(y_reg);

    ProgramCounter = ProgramCounter+1;
    return 2;
}
