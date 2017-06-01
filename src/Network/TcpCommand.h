#ifndef TCPCOMMAND_H
#define TCPCOMMAND_H

#include <vector>
#include <string>

class TcpCommand
{
public:
    TcpCommand();

    std::string getName();
    std::string getId();
    void exec();
    void insertData(std::vector<uint8_t> data);

protected:
    std::vector<uint8_t> buffer;

};

#endif // TCPCOMMAND_H
