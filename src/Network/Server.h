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

};

#endif // SERVER_H
