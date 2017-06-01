#ifndef TCPCONNECTIONPARSER_H
#define TCPCONNECTIONPARSER_H

#include "TcpConnection.h"


#define CON_CONTROL COCTRL
#define CON_UART    COUART
#define CON_I2C     CONI2C
#define CON_SPI     CONSPI

class TcpConnectionParser
{
public:
    TcpConnectionParser();
    void Parse(TcpConnection::SharedPtr con);
};


#endif // TCPCONNECTIONPARSER_H
