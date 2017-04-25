#include "Server.h"

Server::Server(int _Port)
{
    this->Port = _Port;
    this->tcp_endpoint = tcp::endpoint(boost::asio::ip::tcp::v4(),Port);
}

void Server::Start()
{
    this->handler_thread = new std::thread(std::bind(&Server::run,this));
}

void Server::run()
{
    tcp_acceptor.listen();
    //tcp_acceptor.async_accept(tcp_socket, accept_handler);
    ioservice.run();
}

void Server::accept_handler(const boost::system::error_code &ec)
{
    if (!ec)
    {
        std::time_t now = std::time(nullptr);
        data = std::ctime(&now);
       // async_write(tcp_socket, buffer(data), write_handler);
    }
}
