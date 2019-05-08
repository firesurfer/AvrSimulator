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

#include "SWAP.h"

SWAP::SWAP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000000010;
    commandMask = 0b1111111000001111;
    numArgs = 2;
    commandSize = 1;
    name = "SWAP";
}

uint32_t SWAP::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t reg = (instruction & 0x1F0) >> 4;
    uint8_t value = data_memory->getRegister(reg);
    uint8_t lownibble = value & 0b00001111;
    uint8_t highnibble = value & 0b11110000;
    value = highnibble >> 4 | lownibble << 4;
    data_memory->setRegister(reg,value);
    ProgramCounter += 1;
    return 1;
}
