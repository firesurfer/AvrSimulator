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

#include "RET.h"

RET::RET(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010100001000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "RET";
}

uint32_t RET::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t high_byte = data_memory->popStack();
    uint8_t low_byte = data_memory->popStack();

    uint16_t address = (uint16_t)low_byte | ((uint16_t)high_byte<<8);

    LOG(Debug) << "RET: Address: 0x"<<std::hex<< address << std::endl;

    ProgramCounter = address;
    return 4;
}
