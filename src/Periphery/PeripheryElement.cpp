#include "PeripheryElement.h"

PeripheryElement::PeripheryElement(MemoryMapper *mapper)
{
    this->mem_mapper = mapper;
}

void PeripheryElement::handle(uint32_t cycles)
{

}

void PeripheryElement::add_network_connection(TcpConnection::SharedPtr connection)
{
    this->network_connections.push_back(connection);
}
