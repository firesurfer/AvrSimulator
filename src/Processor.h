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
    Processor(uint8_t multipurposeRegisters, ProgramMemory* _program_memory, MemoryMapper* _data_memory);
    bool ExecuteStep();

private:
    /*Registers*/
    std::vector<uint8_t> registers;
    std::vector<uint8_t> hardware_registers;
    std::vector<uint8_t> special_registers;

    uint16_t stack_pointer;
    uint16_t program_counter;


    ProgramMemory * program_memory;
    MemoryMapper * data_memory;
    std::map<uint32_t, CommandBase*> commands;




};

#endif // PROCESSOR_H
