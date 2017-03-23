#include "Processor.h"

Processor::Processor(uint8_t multipurposeRegisters, ProgramMemory *_program_memory, MemoryMapper *_data_memory)
{
    for(int i = 0; i <multipurposeRegisters; i++)
        this->registers.push_back(0);

    for(int i = 0; i < 64; i++)
        this->hardware_registers.push_back(0);
    for(int i= 0; i < SPECIAL_REGISTERS_SIZE; i++)
        this->special_registers.push_back(0);

    this->program_memory = _program_memory;
    this->data_memory = _data_memory;


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
