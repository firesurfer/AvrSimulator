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
