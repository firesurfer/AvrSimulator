#ifndef IOPORT_H
#define IOPORT_H
#include "PeripheryElement.h"
class IOPort: public PeripheryElement
{
public:
    IOPort(MemoryMapper* mapper);
};

#endif // IOPORT_H
