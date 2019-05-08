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

#ifndef TCPCOMMANDSTREAMPARSER_H
#define TCPCOMMANDSTREAMPARSER_H


#include "Network/TcpConnection.h"
#include "Network/TcpCommand.h"
#include <vector>
#include "PeripheryHandler.h"
#include "Processor.h"
class TcpCommandStreamParser
{
public:
    TcpCommandStreamParser(PeripheryHandler* _periphhandler, Processor*  _cpu);
    void AddConnection(TcpConnection::SharedPtr con);
    void RegisterCommand(TcpCommand* cmd);
    void Handle();
private:
    std::vector<TcpConnection::SharedPtr> connections;
    std::vector<TcpCommand*> commands;
    PeripheryHandler* peripheryHandler;
    Processor* processor;
};

#endif // TCPCOMMANDSTREAMPARSER_H
