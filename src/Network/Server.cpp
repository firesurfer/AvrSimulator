#include "Server.h"

Server::Server(int _Port)
{
    this->Port = _Port;
    this->tcp_endpoint = tcp::endpoint(boost::asio::ip::tcp::v4(),Port);
}

void Server::Start()
{
    this->handler_thread = new std::thread(std::bind(&Server::Run,this));
}

void Server::AddNewConnectionCallback(std::function<void (TcpConnection::SharedPtr)> _callback)
{
    this->NewConnectionHandlers.push_back(_callback);
}

void Server::Run()
{
    tcp_acceptor.listen();
    using namespace std::placeholders;
    tcp_acceptor.async_accept(tcp_socket, std::bind(&Server::accept_handler,this, _1));
    ioservice.run();
}

void Server::accept_handler(const boost::system::error_code &ec)
{
    LOG(Debug) << "Got new connection" << std::endl;
    if (!ec)
    {
        TcpConnection::SharedPtr connection = std::make_shared<TcpConnection>(tcp_acceptor.get_io_service());
        Connections.push_back(connection);
        for(auto & func: this->NewConnectionHandlers)
        {
            if(func)
                func(connection);
        }
    }
     using namespace std::placeholders;
     tcp_acceptor.async_accept(tcp_socket, std::bind(&Server::accept_handler,this, _1));
}
