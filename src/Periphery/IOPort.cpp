/*
   Copyright 2019 Friedolin Groeger, Lennart Nachtigall

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "IOPort.h"
#include "BitHelpers.h"

IOPort::IOPort(MemoryMapper *mapper,Port _port):PeripheryElement(mapper)
{
    this->port = _port;
    portDirections.resize(8,IODirection::INPUT);
    portData.resize(8, false);
    portInput.resize(8,false);

    using namespace  std::placeholders;
    dataMem->watchWrite(port.inputRegister, std::bind(&IOPort::onPinChange, this, _1,_2,_3,_4));
}

void IOPort::handle(uint32_t cycles)
{
    //Get datadirection register
    uint8_t ddr = dataMem->getDirect(port.dataDirection);

    //Get output register
    uint8_t data = dataMem->getDirect(port.dataRegister);

    //Check if anything has changes
    bool change = false;
    if(ddr != lastDDR || data != lastPORT)
    {
        change = true;
        lastDDR = ddr;
        lastPORT = data;
    }
    //Step through all bits
    for(uint8_t i = 0;i < 8;i++)
    {
        if( ddr & (1<<i)) //Direction register
        {
            portDirections[i] = IODirection::OUTPUT;
        }
        else
        {
            portDirections[i] = IODirection::INPUT;
        }

        if(data & (1<<i)) //Output register
        {
            portData[i] = true;
        }
        else
        {
            portData[i] = false;
        }
    }

    if(change) // In case something has changed log it
    {
        LOG(Info) << "Port: " << port.portName << std::endl;
        std::string infoString = "Directions: ";
        for(uint8_t i = 0; i < 8;i++)
        {
            infoString += std::to_string((int)portDirections[i]);
        }
        infoString += " State: ";
        for(uint8_t i = 0; i < 8;i++)
        {
            infoString += std::to_string((int)portData[i]);
        }
        LOG(Info) << infoString << std::endl;
    }

}

void IOPort::onPinChange(int32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref)
{
    //avoid write access to PIN register
    ref = oldval;
    //toggle bits in PORT register
    uint8_t data = dataMem->getDirect(port.dataRegister);
    data = data ^ newval;
    dataMem->setDirect(port.dataRegister,data);
}

void IOPort::setInput(std::vector<bool> data)
{
    if(data.size() != 8)
        throw  std::runtime_error("Wrong vector size: size != 8");

    //Get datadirection register
    uint8_t ddr = memMapper->getData(port.dataDirection);

    //Get input register
    uint8_t pin = memMapper->getData(port.inputRegister);

    for(uint8_t i = 0;i < 8;i++)
    {
        //It is an input
        if(!(ddr & (1<<i)))
        {
            if(data[i])
            {
                BitHelpers::set_bit(pin,i);
            }
            else
            {
                BitHelpers::clear_bit(pin,i);
            }
        }
    }
    memMapper->setData(port.inputRegister, pin);
}

std::vector<IODirection> IOPort::getDirections()
{
    return portDirections;
}

std::vector<bool> IOPort::getOutput()
{
    return portData;
}

Port IOPort::getPort()
{
    return port;
}
