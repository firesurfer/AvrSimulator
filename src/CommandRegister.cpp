#include "CommandRegister.h"

CommandRegister::CommandRegister(Processor *processor, MemoryMapper *mapper)
{
    RJMP* rjmp_cmd = new RJMP(mapper);
    NOP* nop_cmd = new NOP(mapper);

    processor->RegisterCommand(rjmp_cmd);
    processor->RegisterCommand(nop_cmd);
}
