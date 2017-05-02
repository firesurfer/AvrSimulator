#include "NetworkHandler.h"

NetworkHandler::NetworkHandler(PeripheryHandler *_periphHandler, int Port)
{

}

int NetworkHandler::GetListenerPort()
{
    this->NetworkServer->GetPort();
}
