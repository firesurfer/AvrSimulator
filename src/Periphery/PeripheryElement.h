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

#ifndef PERIPHERYELEMENT_H
#define PERIPHERYELEMENT_H


#include "MemoryMapper.h"
#include "Network/TcpConnection.h"
class PeripheryElement
{
public:
    PeripheryElement(MemoryMapper* mapper);
    virtual void handle(uint32_t cycles);
    virtual void add_network_connection(TcpConnection::SharedPtr connection);
protected:
    MemoryMapper* memMapper;
    DataMemory* dataMem;
    std::vector<TcpConnection::SharedPtr> network_connections;
};

#endif // PERIPHERYELEMENT_H
