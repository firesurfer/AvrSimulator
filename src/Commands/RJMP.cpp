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

#include "RJMP.h"

RJMP::RJMP(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1100000000000000;
    numArgs = 1;
    commandSize = 1;
    commandMask = 0b1111000000000000;
    name = "RJMP";
}

uint32_t RJMP::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{
    int16_t offset = ((instruction & ~CommandMask()) << 4)  ;
    offset /= 16;


    ProgramCounter = ProgramCounter + offset +1 ;
    return 1;
}
