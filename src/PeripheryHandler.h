#ifndef PERIPHERYHANDLER_H
#define PERIPHERYHANDLER_H

#include "MemoryMapper.h"
#include <vector>
#include <Periphery/PeripheryElement.h>
class PeripheryHandler
{
public:
    PeripheryHandler(MemoryMapper* _mem_mapper);
    void handlePeriphery(uint32_t cycles);
    void addPeripheryElement(PeripheryElement* element);
    std::vector<PeripheryElement*> get_all_elements();
private:
    MemoryMapper* memory_mapper;
    std::vector<PeripheryElement*> periphery_elements;
};

#endif // PERIPHERYHANDLER_H
