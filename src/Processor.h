#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "MemoryMapper.h"
#include "ProgramMemory.h"
#include <vector>
#include "ProcessorDefines.h"
#include <map>
#include "Commands/CommandBase.h"


class Processor
{
public:
    Processor( MemoryMapper* _memory_mapper);
    bool ExecuteStep();
    void RegisterCommand(CommandBase* cmd);
private:

    uint16_t program_counter;


    ProgramMemory * program_memory;
    MemoryMapper * memory_mapper;
    std::map<uint16_t, CommandBase*> commands;




};

#endif // PROCESSOR_H
