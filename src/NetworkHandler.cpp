#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(PeripheryHandler *_periphHandler, int Port)
{
    this->PeriphHandler = _periphHandler;
    this->NetworkServer = new Server(Port);
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
