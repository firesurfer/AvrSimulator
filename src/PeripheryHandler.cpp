#include "PeripheryHandler.h"

PeripheryHandler::PeripheryHandler(MemoryMapper *_mem_mapper)
{
    this->memory_mapper = _mem_mapper;
}

void PeripheryHandler::handlePeriphery(uint16_t cycles)
{

}

void PeripheryHandler::addPeripheryElement(PeripheryElement *element)
{
    this->periphery_elements.push_back(element);
}
