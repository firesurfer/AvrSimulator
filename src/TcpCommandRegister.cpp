#include "TcpCommandRegister.h"

TcpCommandRegister::TcpCommandRegister(TcpCommandStreamParser &parser)
{
    parser.RegisterCommand(&start_cmd);
}
