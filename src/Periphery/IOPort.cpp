#include "IOPort.h"

IOPort::IOPort(MemoryMapper *mapper,Port _port):PeripheryElement(mapper)
{
    this->port = _port;
}

void IOPort::handle(uint32_t cycles)
{

}
