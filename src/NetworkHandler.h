#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include "Network/Server.h"
#include "PeripheryHandler.h"

class NetworkHandler
{
public:
    NetworkHandler(PeripheryHandler* _periphHandler, int Port);

    int GetListenerPort();
private:
    PeripheryHandler* PeriphHandler;
    Server* NetworkServer;

    void OnNewConnection(TcpConnection::SharedPtr connection);

};

#endif // NETWORKHANDLER_H
