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

IOPort::IOPort(MemoryMapper *mapper,Port _port):PeripheryElement(mapper)
{
    this->port = _port;
    portDirections.resize(8,IODirection::INPUT);
    portData.resize(8, false);
    portInput.resize(8,false);

    using namespace  std::placeholders;
    memMapper->watch(port.inputRegister, std::bind(&IOPort::onPinChange, this, _1,_2,_3,_4));
}

void IOPort::handle(uint32_t cycles)
{


    //Get datadirection register
    uint8_t ddr = memMapper->getData(port.dataDirection);
    //Get input register
    uint8_t pin = memMapper->getData(port.inputRegister);
    //Get output register
    uint8_t data = memMapper->getData(port.dataRegister);

    bool change = false;
    if(ddr != lastDDR || pin != lastPIN || data != lastPORT)
    {
        change = true;
        lastDDR = ddr;
        lastPIN = pin;
        lastPORT = data;
    }



    for(uint8_t i = 0;i < 8;i++)
    {
        if( ddr & (1<<i))
        {
            portDirections[i] = IODirection::OUTPUT;
        }
        else {
            portDirections[i] = IODirection::INPUT;
        }
        if(pin & (1<<i))
        {
            //If a pin is configured as output writing a one to the PINx register results into toggling the pin
            if(portDirections[i] != IODirection::OUTPUT)
            {
                portInput[i] = true;
            }


        }
        else {
            portInput[i] = false;
        }
        if(data & (1<<i))
        {
            portData[i] = true;
        }
        else {
            portData[i] = false;
        }
    }

    if(change)
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
    //Get datadirection register
    uint8_t ddr = memMapper->getData(port.dataDirection);
    uint8_t pin = newval;
    //Get output register
    uint8_t data = memMapper->getData(port.dataRegister);
    for(uint8_t i = 0;i < 8;i++)
    {
        if(pin & (1<<i))
        {
            //If a pin is configured as output writing a one to the PINx register results into toggling the pin
            if(portDirections[i] == IODirection::OUTPUT)
            {
                data = data ^ (1<<i);
                memMapper->setData(port.dataRegister,data);
            }
            else {
                portInput[i] = true;
            }

        }
    }
}
