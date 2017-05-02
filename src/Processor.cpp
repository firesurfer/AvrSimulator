#include "Processor.h"

using namespace std;

Processor::Processor(MemoryMapper *_memory_mapper, PeripheryHandler* _periph_handler, InterruptController *_intcontrl)
{
    this->program_counter = 0;
    this->memory_mapper = _memory_mapper;
    this->program_memory = memory_mapper->getProgramMemory();
    this->periph_handler =_periph_handler;
    this->intController = _intcontrl;
    this->decoder = new Decoder(commands);
}

bool Processor::ExecuteStep()
{

    if(program_counter >= program_memory->GetSize())
        return false;
    else
    {
        int sp1=0,sp2=0,sp=this->memory_mapper->getStackPtr();
        try{
            sp1 = this->memory_mapper->getData(sp+1);
        }catch(...){sp1=-1;}
        try{
            sp2 = this->memory_mapper->getData(sp+2);
        }catch(...){sp2=-1;}
        LOG(Debug) << "SREG: 0x" << hex << (int)this->memory_mapper->getSREG();
        LOG_APPEND << "  Stackptr: 0x" << hex << sp;
        if(sp1 != -1)
            LOG_APPEND << " SP+1: 0x" << sp1;
        if(sp2 != -1)
            LOG_APPEND << " SP+2: 0x" << sp2;
        LOG_APPEND << endl;

        uint16_t instruction = program_memory->Get(program_counter);
        bool found = false;

       /* if(instruction == 0xCFFF)
        {
            LOG(Warning)<< "Found empty endless loop (0xCFFF) on address 0x" << hex << program_counter*2 << " - Aborting programm" << endl;
            return false;
        }*/
        CommandBase* next_command = decoder->decode(instruction);
        if(!next_command)
        {
            LOG(Fatal) << "Illegal instruction: " << hex << instruction << " on address: " << program_counter*2 <<endl;
            throw runtime_error("Error: illegal instruction!");
        }
        uint32_t cycles=0;
        if(!flags.skipNextInstruction){
            LOG(Info) << "Instruction 0x" << hex << program_counter*2 << ": 0x" << instruction << " " << next_command->Name() << endl;
            cycles = next_command->Execute(instruction,this->program_counter, flags);
        }else{
            LOG(Info) << "skipping 0x" << hex <<program_counter*2 << ": 0x" << instruction << " " << next_command->Name() << endl;
            cycles = next_command->CommandSize();
            program_counter += next_command->CommandSize();
            flags.skipNextInstruction = false;
        }
        periph_handler->handlePeriphery(cycles);
        intController->handleInterrupts(cycles,program_counter,flags);

        return true;
    }

}

void Processor::RegisterCommand(CommandBase *cmd)
{
    this->commands.push_back(cmd);
}

void Processor::PrintRegisteredCommands()
{
    LOG(Debug)  << "List of all known instructions: " << endl;
    for(auto & it: commands)
    {
        LOG(Debug)<< "    0x" << hex << it->GetCommand() << " " << it->Name()<< endl;
    }
    LOG(Debug) << "#######################################" << endl;
}
