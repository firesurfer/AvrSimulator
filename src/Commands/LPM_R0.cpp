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

#include "LPM_R0.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

LPM_R0::LPM_R0(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010111001000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "LMP_R0";
}

uint32_t LPM_R0::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    UNUSED(instruction);
    uint16_t address = data_memory->getZReg();
    if(address&0x01)
        data_memory->setRegister(R0, data_memory->getProgramMemory()->get(address>>1)>>8);
    else
        data_memory->setRegister(R0, data_memory->getProgramMemory()->get(address>>1));
    ProgramCounter += 1;
    return 3;
}
