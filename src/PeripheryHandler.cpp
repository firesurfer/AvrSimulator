#include "PeripheryHandler.h"

PeripheryHandler::PeripheryHandler(MemoryMapper *_mem_mapper)
{
    this->memory_mapper = _mem_mapper;
}

void PeripheryHandler::handlePeriphery(uint32_t cycles)
{
    for(PeripheryElement* & element: this->periphery_elements)
    {
        element->handle(cycles);
    }
}

void PeripheryHandler::addPeripheryElement(PeripheryElement *element)
{
    this->periphery_elements.push_back(element);
}

std::vector<PeripheryElement *> PeripheryHandler::get_all_elements()
{
    return this->periphery_elements;
}
