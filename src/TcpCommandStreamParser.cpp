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

#include "TcpCommandStreamParser.h"

TcpCommandStreamParser::TcpCommandStreamParser(PeripheryHandler *_periphhandler, Processor *_cpu)
{
    this->peripheryHandler = _periphhandler;
    this->processor = _cpu;
}

void TcpCommandStreamParser::AddConnection(TcpConnection::SharedPtr con)
{
    connections.push_back(con);
}

void TcpCommandStreamParser::RegisterCommand(TcpCommand *cmd)
{
    if(cmd != nullptr)
        this->commands.push_back(cmd);
}

void TcpCommandStreamParser::Handle()
{
    for(TcpConnection::SharedPtr con: this->connections)
    {
        int actual_length = 0;
        auto data = con->Read(1, actual_length);
        for(TcpCommand* cmd: this->commands)
        {
            cmd->insertData(data);
        }

    }
}
