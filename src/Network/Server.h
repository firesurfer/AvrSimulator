#ifndef SERVER_H
#define SERVER_H

#include <boost/asio/io_service.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>
#include <ctime>
#include <thread>
using namespace boost::asio;
using namespace boost::asio::ip;




class Server
{
public:
    Server(int _Port);

    void Start();
private:
    io_service ioservice;
    tcp::endpoint tcp_endpoint;
    tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
    tcp::socket tcp_socket{ioservice};
    std::string data;

    std::thread* handler_thread;

    int Port;

    void run();

    void accept_handler(const boost::system::error_code &ec);

};

#endif // SERVER_H
