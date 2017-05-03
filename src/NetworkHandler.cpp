#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(PeripheryHandler *_periphHandler, int Port)
{
    LOG(Info) << "Started network server: "<<std::dec<< Port << std::endl;

    this->PeriphHandler = _periphHandler;
    this->NetworkServer = new Server(Port);
    this->NetworkServer->Start();
    this->NetworkServer->AddNewConnectionCallback(std::bind(&NetworkHandler::OnNewConnection, this,std::placeholders::_1));

}

int NetworkHandler::GetListenerPort()
{
    this->NetworkServer->GetPort();
}

void NetworkHandler::OnNewConnection(TcpConnection::SharedPtr connection)
{
    int length = 0;
    auto result = connection->Read(4,length);
    //TODO check type of connection
    for(PeripheryElement* & periph: this->PeriphHandler->get_all_elements())
    {
        //It's the responsibility of the hardware connection to read data from the connection!
        periph->add_network_connection(connection);
    }

}
