#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <memory>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
class TcpConnection: public std::enable_shared_from_this<TcpConnection>
{
public:
    typedef std::shared_ptr<TcpConnection> SharedPtr;
    TcpConnection(boost::asio::io_service& io_service);
    tcp::socket& GetSocket();


    void Write(std::vector<uint8_t> _data);
    //TODO provide method that takes buffer instead
    std::vector<uint8_t> Read(int desired_length, int& actual_length);

private:
    tcp::socket Socket;
    std::string Message;
};

#endif // TCPCONNECTION_H
