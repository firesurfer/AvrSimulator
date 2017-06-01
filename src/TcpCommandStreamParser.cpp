#include "TcpCommandStreamParser.h"

TcpCommandStreamParser::TcpCommandStreamParser(PeripheryHandler *_periphhandler, Processor *_cpu)
{
    this->peripheryHandler = _periphhandler;
    this->processor = _cpu;
}

void TcpCommandStreamParser::AddConnection(TcpConnection::SharedPtr con)
{
    connections.push_back(con);
}

void TcpCommandStreamParser::RegisterCommand(TcpCommand *cmd)
{
    if(cmd != nullptr)
        this->commands.push_back(cmd);
}

void TcpCommandStreamParser::Handle()
{
    for(TcpConnection::SharedPtr con: this->connections)
    {
        int actual_length = 0;
        auto data = con->Read(1, actual_length);
        for(TcpCommand* cmd: this->commands)
        {
            cmd->insertData(data);
        }

    }
}
