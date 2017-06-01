#ifndef TCPCOMMANDREGISTER_H
#define TCPCOMMANDREGISTER_H


#include "Network/TcpCommand.h"
#include "TcpCommandStreamParser.h"
#include "Network/TcpCommandStart.h"
class TcpCommandRegister
{
public:
    TcpCommandRegister(TcpCommandStreamParser& parser);
private:
    TcpCommandStart start_cmd;

};

#endif // TCPCOMMANDREGISTER_H
