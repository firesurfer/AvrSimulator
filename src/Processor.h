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

#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <vector>
#include <map>

#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include "ProcessorDefines.h"
#include "Commands/CommandBase.h"
#include "PeripheryHandler.h"
#include "InterruptController.h"
#include "Logger/Logger.h"
#include "Decoder.h"
#include "processorflags.h"
class Processor
{
public:
    Processor(MemoryMapper* _memory_mapper, PeripheryHandler *_periph_handler, InterruptController *_intcontrl);
    bool ExecuteStep();
    void RegisterCommand(CommandBase* cmd);
    void PrintRegisteredCommands();
private:

    uint16_t program_counter;


    ProgramMemory * program_memory;
    MemoryMapper * memory_mapper;
    PeripheryHandler* periph_handler;
    InterruptController *intController;
    std::vector<CommandBase*> commands;
    Decoder* decoder;
    ProcessorFlags flags;




};

#endif // PROCESSOR_H
