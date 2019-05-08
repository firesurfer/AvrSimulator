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

#include "XCH.h"
#include "FlagCalculator.h"

using namespace FlagCalculator;

XCH::XCH(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b0001110000000000;
    commandMask = 0b1111110000000000;
    numArgs = 2;
    commandSize = 1;
    name = "XCH";
}

uint32_t XCH::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

    uint8_t reg = (instruction & 0x1F0) >> 4;
    uint8_t regData = data_memory->getRegister(reg);
    uint16_t address = data_memory->getZReg();
    uint8_t data = data_memory->getData(address);

    data_memory->setData(address,regData);
    data_memory->setRegister(reg,data);
    ProgramCounter += 1;
    return 1;
}
