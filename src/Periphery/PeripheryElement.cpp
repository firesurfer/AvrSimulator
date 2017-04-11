#include "PeripheryElement.h"

PeripheryElement::PeripheryElement(MemoryMapper *mapper)
{
    this->mem_mapper = mapper;
}

void PeripheryElement::handle(uint32_t cycles)
{

}
