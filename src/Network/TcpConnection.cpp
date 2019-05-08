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

#include "TcpConnection.h"

TcpConnection::TcpConnection(boost::asio::io_service &io_service):Socket(io_service)
{
    this->ConnectionIdentifier = "Default";
}


tcp::socket &TcpConnection::GetSocket()
{
    return Socket;
}


void TcpConnection::Write(std::vector<uint8_t> _data)
{
    boost::system::error_code error;
    boost::asio::write(Socket, boost::asio::buffer(_data),error);
    //TODO read error code
    //if(error != boost::system::error_code::)
}

void TcpConnection::Write(std::__cxx11::string _data)
{
    boost::system::error_code error;
    boost::asio::write(Socket, boost::asio::buffer(_data),error);
}

std::__cxx11::string TcpConnection::GetConnectionIdentifier()
{
    return ConnectionIdentifier;
}

void TcpConnection::SetConnectionIdentifier(std::__cxx11::string id)
{
    this->ConnectionIdentifier = id;
}

std::vector<uint8_t> TcpConnection::Read(int desired_length, int &actual_length)
{
    uint8_t buffer[desired_length];
    if(Socket.available() > desired_length)
    {
        actual_length =boost::asio::read(Socket,boost::asio::buffer(buffer, desired_length));
        std::vector<uint8_t> return_vector;
        for(int i = 0; i < actual_length; i++)
        {
            return_vector.push_back(buffer[i]);
        }
        return return_vector;
    }
    actual_length = 0;
    return std::vector<uint8_t>();

}

std::vector<uint8_t> TcpConnection::ReadBlocking(int desired_length)
{
    uint8_t buffer[desired_length];

    int actual_length =boost::asio::read(Socket,boost::asio::buffer(buffer, desired_length));
    std::vector<uint8_t> return_vector;
    for(int i = 0; i < actual_length; i++)
    {
        return_vector.push_back(buffer[i]);
    }
    return return_vector;

}

void TcpConnection::AsyncRead(int desired_length, std::function<void (std::vector<uint8_t>)> callback)
{
    uint8_t buffer[desired_length];
    auto func = [&](const boost::system::error_code& err, std::size_t bytes_transferred)
    {
        if(!err)
        {
            if(bytes_transferred > 0)
            {
                std::vector<uint8_t> data;
                for(int i= 0; i < bytes_transferred;i++)
                    data.push_back(buffer[i]);
                if(callback)
                    callback(data);
            }
        }
    };

    boost::asio::async_read(Socket, boost::asio::buffer(buffer, desired_length), func);
}


