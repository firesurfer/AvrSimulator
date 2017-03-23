#include "Processor.h"

Processor::Processor(MemoryMapper *_memory_mapper)
{

    this->memory_mapper = _memory_mapper;
    this->program_memory = memory_mapper->getProgramMemory();



}

bool Processor::ExecuteStep()
{

    if(program_counter >= program_memory->GetSize())
        return false;
    else
    {
        uint16_t instruction = program_memory->Get(program_counter);
        for(auto & it: commands)
        {
            if((instruction & it.second->CommandMask()) == it.first)
            {
                program_counter = it.second->Execute(instruction,this->program_counter);

            }
        }

        throw std::runtime_error("Error: illegal instruction!");
    }
}
