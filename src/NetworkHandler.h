#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include "Network/Server.h"
#include "PeripheryHandler.h"
#include <functional>
#include "TcpCommandStreamParser.h"
#include "Network/TcpConnectionParser.h"
class NetworkHandler
{
public:
    NetworkHandler(PeripheryHandler* _periphHandler,TcpCommandStreamParser* _cmd_parser, int Port);

    int GetListenerPort();
private:
    PeripheryHandler* PeriphHandler;
    Server NetworkServer;
    TcpCommandStreamParser* cmd_parser;
    void OnNewConnection(TcpConnection::SharedPtr connection);

};

#endif // NETWORKHANDLER_H
