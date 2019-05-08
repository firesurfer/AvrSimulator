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

#include "SPM.h"

SPM::SPM(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010111101000;
    commandMask = 0xFFFF;
    numArgs = 2;
    commandSize = 1;
    name = "SPM";
}

uint32_t SPM::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    uint8_t high_byte = data_memory->getRegister(R0+1);
    uint8_t low_byte = data_memory->getRegister(R0);
    uint16_t data = low_byte | (high_byte <<8);
    uint16_t address = data_memory->getZReg();
    data_memory->getProgramMemory()->set(address,data);
    ProgramCounter+=1;
    return 2;//TODO
}
