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

#ifndef TCPCOMMAND_H
#define TCPCOMMAND_H

#include <vector>
#include <string>

class TcpCommand
{
public:
    TcpCommand();

    std::string getName();
    std::string getId();
    void exec();
    void insertData(std::vector<uint8_t> data);

protected:
    std::vector<uint8_t> buffer;

};

#endif // TCPCOMMAND_H
