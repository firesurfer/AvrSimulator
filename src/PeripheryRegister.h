#ifndef PERIPHERYREGISTER_H
#define PERIPHERYREGISTER_H
#include "PeripheryHandler.h"

class PeripheryRegister
{
public:
    static void registerPeriphery(PeripheryHandler* handler, MemoryMapper* mapper);
};

#endif // PERIPHERYREGISTER_H
