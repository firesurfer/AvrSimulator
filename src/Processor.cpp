#include "Processor.h"

Processor::Processor(uint8_t multipurposeRegisters, ProgramMemory *_program_memory, DataMemory *_data_memory)
{
    for(int i = 0; i <multipurposeRegisters; i++)
        this->registers.push_back(0);

    for(int i = 0; i < 64; i++)
        this->hardware_registers.push_back(0);
    for(int i= 0; i < SPECIAL_REGISTERS_SIZE; i++)
        this->special_registers.push_back(0);

    this->program_memory = _program_memory;
    this->data_memory = _data_memory;

    MoveCommand* mv_cmd = new MoveCommand(data_memory);
    commands[mv_cmd->GetCommand()] = mv_cmd;
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
            if((instruction & it.first) == it.first)
            {
                uint8_t instruction_size = (it.second->CommandSize() -2)/2;
                if(instruction_size>0)
                {
                    std::vector<uint8_t> additionalWords;
                    for(int i = 0; i < instruction_size;i++)
                    {
                        additionalWords.push_back(program_memory->Get(program_counter+i));
                    }
                    program_counter = it.second->Execute(instruction,additionalWords, this->registers, this->special_registers,this->program_counter,this->stack_pointer);
                }
                else
                    program_counter = it.second->Execute(instruction,{}, this->registers, this->special_registers,this->program_counter,this->stack_pointer);

                return true;
            }
        }

        throw std::runtime_error("Error: illegal instruction!");
    }
}
