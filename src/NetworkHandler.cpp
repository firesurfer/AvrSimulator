/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
