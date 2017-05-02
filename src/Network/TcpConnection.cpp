#include "TcpConnection.h"

TcpConnection::TcpConnection(boost::asio::io_service &io_service):Socket(io_service)
{

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

std::vector<uint8_t> TcpConnection::Read(int desired_length, int &actual_length)
{
    uint8_t buffer[desired_length];
    actual_length =boost::asio::read(Socket,boost::asio::buffer(buffer, desired_length));
    std::vector<uint8_t> return_vector;
    for(int i = 0; i < actual_length; i++)
    {
        return_vector.push_back(buffer[i]);
    }
    return return_vector;
}
