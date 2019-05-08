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

#include "ST_X.h"

ST_X::ST_X(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001001000001100;
    commandMask = 0b1111111000001100;
    numArgs = 1;
    commandSize = 1;
    name = "ST_X";
}

uint32_t ST_X::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t ld_x = (instruction) & 0b00000011;
    uint8_t reg = (instruction>>4) & 0x1F;

    uint16_t x_reg = data_memory->getXReg();
    switch(ld_x)
    {
    case 0b00:
        data_memory->setData(x_reg,data_memory->getRegister(reg));
        //Unchanged
        break;
    case 0b01:
        data_memory->setData(x_reg,data_memory->getRegister(reg));
        //Post increment
        x_reg++;
        break;
    case 0b10:
        x_reg--;
        data_memory->setData(x_reg,data_memory->getRegister(reg));
        //Pre decrement
        break;
    }
    data_memory->setXReg(x_reg);


    ProgramCounter += 1;
    return 2;
}
