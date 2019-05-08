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

#include "CALL.h"

CALL::CALL(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010000001110;
    commandMask = 0b1111111000001110;
    numArgs = 1;
    commandSize = 2;
    name = "CALL";
}

uint32_t CALL::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    uint32_t address = data_memory->getProgramMemory()->Get(ProgramCounter+1);
    address |= uint32_t(instruction&0x0001)<<16 | uint32_t(instruction&0x01F0)<<13;

    uint8_t low_byte = (uint8_t)ProgramCounter+2;
    uint8_t high_byte = (uint8_t)((ProgramCounter+2) >> 8);

    LOG(Debug) << "CALL: Address: 0x" << std::hex<< address << ", Stack: 0x" << std::hex << (int)low_byte << " 0x" << (int)high_byte << std::endl;

    data_memory->pushStack(low_byte);
    data_memory->pushStack(high_byte);
    ProgramCounter = address;

    return 4;
}
