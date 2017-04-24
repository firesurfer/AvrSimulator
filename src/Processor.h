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
