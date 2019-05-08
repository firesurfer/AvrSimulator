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

#ifndef SERVER_H
#define SERVER_H

#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/bind.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <ctime>
#include <thread>
#include "TcpConnection.h"
#include <functional>
#include "../Logger/Logger.h"
#include "TcpConnectionParser.h"

using namespace boost::asio;
using namespace boost::asio::ip;




class Server
{
public:
    Server(int _Port);

    void Start();
    void AddNewConnectionCallback(std::function<void(TcpConnection::SharedPtr)> _callback);
    int GetPort(){return Port;}
private:
    io_service ioservice;
    tcp::endpoint tcp_endpoint;
    tcp::acceptor tcp_acceptor;
    tcp::socket tcp_socket;

    std::thread* handler_thread;

    int Port;

    void Run();

    void accept_handler(TcpConnection::SharedPtr connection, const boost::system::error_code &ec);
    std::vector<TcpConnection::SharedPtr> Connections;
    std::vector<std::function<void(TcpConnection::SharedPtr)>> NewConnectionHandlers;
    void start_accept();

    TcpConnectionParser con_parser;

};

#endif // SERVER_H
