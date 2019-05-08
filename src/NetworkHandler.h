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

#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include "Network/Server.h"
#include "PeripheryHandler.h"
#include <functional>
#include "TcpCommandStreamParser.h"
#include "Network/TcpConnectionParser.h"
class NetworkHandler
{
public:
    NetworkHandler(PeripheryHandler* _periphHandler,TcpCommandStreamParser* _cmd_parser, int Port);

    int GetListenerPort();
private:
    PeripheryHandler* PeriphHandler;
    Server NetworkServer;
    TcpCommandStreamParser* cmd_parser;
    void OnNewConnection(TcpConnection::SharedPtr connection);

};

#endif // NETWORKHANDLER_H
