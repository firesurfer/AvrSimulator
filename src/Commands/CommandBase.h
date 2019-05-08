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

#ifndef COMMANDBASE_H
#define COMMANDBASE_H

#include <cstdint>
#include <vector>
#include "MemoryMapper.h"

#include "ProcessorDefines.h"
#include "BitHelpers.h"
#include "Logger/Logger.h"
#include "ProcessorFlags.h"
class CommandBase
{
public:
    CommandBase(MemoryMapper* _dataMemory);
    virtual uint16_t GetCommand() const;
    virtual uint16_t NumberOfArguments() const;
    virtual uint16_t CommandSize() const;
    virtual uint16_t CommandMask() const;
    virtual uint32_t Execute(uint16_t instruction,uint16_t &ProgramCounter, ProcessorFlags &flags);
    virtual std::string Name() const;

protected :
    MemoryMapper* data_memory;
    uint16_t command;
    uint16_t numArgs;
    uint16_t commandSize;
    uint16_t commandMask;
    std::string name;

};

#endif // COMMANDBASE_H
