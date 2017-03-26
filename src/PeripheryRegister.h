#ifndef PERIPHERYREGISTER_H
#define PERIPHERYREGISTER_H
#include "PeripheryHandler.h"

class PeripheryRegister
{
public:
    PeripheryRegister(PeripheryHandler* handler, MemoryMapper* mapper);
};

#endif // PERIPHERYREGISTER_H
