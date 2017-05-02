#ifndef PERIPHERYELEMENT_H
#define PERIPHERYELEMENT_H


#include "MemoryMapper.h"
#include "Network/TcpConnection.h"
class PeripheryElement
{
public:
    PeripheryElement(MemoryMapper* mapper);
    virtual void handle(uint32_t cycles);
    virtual void add_network_connection(TcpConnection::SharedPtr connection);
protected:
    MemoryMapper* mem_mapper;
    std::vector<TcpConnection::SharedPtr> network_connections;
};

#endif // PERIPHERYELEMENT_H
