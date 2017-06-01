#include "TcpCommand.h"

TcpCommand::TcpCommand()
{

}

std::__cxx11::string TcpCommand::getId()
{
    return "NONE";
}

void TcpCommand::insertData(std::vector<uint8_t> data)
{
    buffer.insert(buffer.end(), data.begin(), data.end());
}
