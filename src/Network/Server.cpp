#include "Server.h"

Server::Server(int _Port):tcp_endpoint{boost::asio::ip::tcp::v4(),_Port}, tcp_acceptor{ioservice, tcp_endpoint}, tcp_socket{ioservice}
{
    this->Port = _Port;
    LOG(Info) << "Listening on Port:" << Port << std::endl;

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
    start_accept();
    ioservice.run();
}

void Server::accept_handler(TcpConnection::SharedPtr connection, const boost::system::error_code &ec)
{
    std::cout << "Got new connection" << std::endl;
    if (!ec)
    {
        con_parser.Parse(connection);
        Connections.push_back(connection);
        for(auto & func: this->NewConnectionHandlers)
        {
            if(func)
                func(connection);
        }
    }
    start_accept();
}

void Server::start_accept()
{

    TcpConnection::SharedPtr connection = std::make_shared<TcpConnection>(tcp_acceptor.get_io_service());
    using namespace std::placeholders;
    tcp_acceptor.async_accept(connection->GetSocket(),
           boost::bind(&Server::accept_handler, this, connection,
             boost::asio::placeholders::error));

}
