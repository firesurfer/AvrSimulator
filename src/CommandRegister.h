#ifndef COMMANDREGISTER_H
#define COMMANDREGISTER_H

#include "Processor.h"
#include "Commands/RJMP.h"

class CommandRegister
{
public:
    CommandRegister(Processor* processor, MemoryMapper* mapper);
};

#endif // COMMANDREGISTER_H
