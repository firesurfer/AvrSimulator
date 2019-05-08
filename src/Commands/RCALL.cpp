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

#include "RCALL.h"

RCALL::RCALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1101000000000000;
    commandMask = 0xF000;
    numArgs = 1;
    commandSize = 1;
    name = "RCALL";
}

uint32_t RCALL::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    int16_t address = ((int16_t)(instruction & ~commandMask)<<4);
    address/=16;
    uint8_t low_byte = (uint8_t)(ProgramCounter+1);
    uint8_t high_byte = (uint8_t)((ProgramCounter+1) >> 8);

    data_memory->pushStack(low_byte);
    data_memory->pushStack(high_byte);
    ProgramCounter+= (address+1);
    return 3;
}
