#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <memory>
#include <boost/asio.hpp>
#include <functional>

using boost::asio::ip::tcp;
class TcpConnection: public std::enable_shared_from_this<TcpConnection>
{
public:
    typedef std::shared_ptr<TcpConnection> SharedPtr;
    TcpConnection(boost::asio::io_service& io_service);

    tcp::socket& GetSocket();


    void Write(std::vector<uint8_t> _data);
    void Write(std::string _data);
    virtual std::string GetConnectionIdentifier();
    virtual void SetConnectionIdentifier(std::string id);
    //TODO provide method that takes buffer instead
    std::vector<uint8_t> Read(int desired_length, int& actual_length);
    std::vector<uint8_t> ReadBlocking(int desired_length);
    void AsyncRead(int desired_length, std::function<void(std::vector<uint8_t>)> callback);



private:
    tcp::socket Socket;
    std::string Message;

    std::string ConnectionIdentifier;
};

#endif // TCPCONNECTION_H
