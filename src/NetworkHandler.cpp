#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(PeripheryHandler *_periphHandler,TcpCommandStreamParser* _cmd_parser, int Port):NetworkServer{Port}
{
    LOG(Info) << "Started network server: "<<std::dec<< Port << std::endl;

    this->PeriphHandler = _periphHandler;
    this->cmd_parser = _cmd_parser;
    this->NetworkServer.Start();
    this->NetworkServer.AddNewConnectionCallback(std::bind(&NetworkHandler::OnNewConnection, this,std::placeholders::_1));

}

int NetworkHandler::GetListenerPort()
{
    this->NetworkServer.GetPort();
}

void NetworkHandler::OnNewConnection(TcpConnection::SharedPtr connection)
{

    if(connection->GetConnectionIdentifier() == "CON_CONTROL")


    for(PeripheryElement* & periph: this->PeriphHandler->get_all_elements())
    {

        //It's the responsibility of the hardware connection to read data from the connection!
        periph->add_network_connection(connection);
    }

}
