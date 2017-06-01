#include "TcpConnectionParser.h"

TcpConnectionParser::TcpConnectionParser()
{

}

void TcpConnectionParser::Parse(TcpConnection::SharedPtr con)
{
    //Read the first 6 bytes blocking
    auto data = con->ReadBlocking(6);
    std::string con_str = std::string((char*)data.data());
    if(con_str == "CON_CONTROL")
        con->SetConnectionIdentifier("CON_CONTROL");
    else if(con_str == "CON_UART")
        con->SetConnectionIdentifier("CON_UART");
    //TODO add the rest of the defined connections
}
