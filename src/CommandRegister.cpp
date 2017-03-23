#include "CommandRegister.h"

CommandRegister::CommandRegister(Processor *processor, MemoryMapper *mapper)
{
    RJMP* rjmp_cmd = new RJMP(mapper);

    processor->RegisterCommand(rjmp_cmd);
}
