#ifndef PERIPHERYELEMENT_H
#define PERIPHERYELEMENT_H


#include "MemoryMapper.h"
class PeripheryElement
{
public:
    PeripheryElement(MemoryMapper* mapper);
    virtual void handle();
private:
    MemoryMapper* mem_mapper;
};

#endif // PERIPHERYELEMENT_H
