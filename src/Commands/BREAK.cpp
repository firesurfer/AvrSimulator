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

#include "BREAK.h"

BREAK::BREAK(MemoryMapper *_dataMemory):CommandBase(_dataMemory)
{
    command = 0b1001010110011000;
    commandMask = 0xFFFF;
    numArgs = 0;
    commandSize = 1;
    name = "BREAK";
}

uint32_t BREAK::Execute(uint16_t instruction, uint16_t &ProgramCounter, ProcessorFlags &flags)
{

#ifdef JTAG_ENABLED
    //TODO let some debugging happen
#else
    //We do nothing
#endif
    LOG(Info) << "Breakpoint" << std::endl;
    ProgramCounter+=1;
    return 1;
}
