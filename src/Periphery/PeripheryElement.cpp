#include "PeripheryElement.h"

PeripheryElement::PeripheryElement(MemoryMapper *mapper)
{
    this->memMapper = mapper;
    this->dataMem = mapper->getDataMemory();
}

void PeripheryElement::handle(uint32_t cycles)
{

}

void PeripheryElement::add_network_connection(TcpConnection::SharedPtr connection)
{
    this->network_connections.push_back(connection);
}
