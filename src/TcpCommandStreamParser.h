#ifndef TCPCOMMANDSTREAMPARSER_H
#define TCPCOMMANDSTREAMPARSER_H


#include "Network/TcpConnection.h"
#include "Network/TcpCommand.h"
#include <vector>
#include "PeripheryHandler.h"
#include "Processor.h"
class TcpCommandStreamParser
{
public:
    TcpCommandStreamParser(PeripheryHandler* _periphhandler, Processor*  _cpu);
    void AddConnection(TcpConnection::SharedPtr con);
    void RegisterCommand(TcpCommand* cmd);
    void Handle();
private:
    std::vector<TcpConnection::SharedPtr> connections;
    std::vector<TcpCommand*> commands;
    PeripheryHandler* peripheryHandler;
    Processor* processor;
};

#endif // TCPCOMMANDSTREAMPARSER_H
