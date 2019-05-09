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

#include "Uart.h"

using namespace std;
using namespace std::placeholders;

//const int UDRE=5;
//const int RXC=7;
//const int DOR=3;

Uart::Uart(MemoryMapper *mapper, uint16_t _udr, register_bit_t _udre, register_bit_t _rxc, register_bit_t _dor)
    :PeripheryElement(mapper),udr(_udr),udre(_udre),rxc(_rxc),dor(_dor)
{
    dataMem->watchWrite(udr, std::bind(&Uart::onChange,this,_1,_2,_3,_4));
    dataMem->watchWrite(udre.addr, std::bind(&Uart::onStatus,this,_1,_2,_3,_4));
    dataMem->watchRead(udr, std::bind(&Uart::onRead,this,_1,_2));

    uint8_t tmp = dataMem->getDirect(udre.addr);
    dataMem->setDirect(udre.addr,tmp | (1<<udre.bit));
    receiveCycles = 0;
}

void Uart::handle(uint32_t cycles)
{
    receiveCycles += cycles;
    if(receiveCycles>100){
        for(TcpConnection::SharedPtr & con :network_connections)
        {
            //Simply take the first one
            if(con)
            {
                int actual_length = 0;
                std::vector<uint8_t> data = con->Read(1,actual_length);
                if(actual_length > 0){
                    uint8_t tmp = dataMem->getDirect(rxc.addr);
                    if(tmp & (1<<rxc.bit)){
                        dataMem->setDirect(dor.addr,tmp | (1<<dor.bit));
                        LOG(Info) << "Uart receive overrun: "<< data[0] << std::endl;
                    }else{
                        LOG(Info) << "Uart receive: "<< data[0] << std::endl;
                        dataMem->setDirect(udr,data[0]);
                        dataMem->setDirect(rxc.addr,tmp | (1<<rxc.bit));
                        receiveCycles = 0;
                    }
                }
                //break;
            }
        }
    }
}

void Uart::onChange(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref)
{
    ref=oldval;//dont change UDR because its also the receive register
    LOG(Info)<<"Uart: '"<<newval<<"'"<<endl;
    for(TcpConnection::SharedPtr & con: network_connections)
    {
        if(con)
        {
            LOG(Important) << "Writing to connection" << std::endl;
            con->Write(string((char*)&newval,1));
        }
    }
    if(newval=='\n'){
        LOG(Important)<<"UART: "<<buffer<<endl;
        buffer="";
    }else
        buffer+=newval;
    uint8_t tmp = dataMem->getDirect(udre.addr);
    dataMem->setDirect(udre.addr,tmp | (1<<udre.bit));
}

void Uart::onStatus(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref)
{
    LOG(Info)<<"UCSRA changed: "<<(int)oldval<<" -> "<<(int)newval<<" : "<<(int)ref<<endl;
    //clear flag if 1 is written
    if(newval & (1<<udre.bit)){
        ref &= ~(1<<udre.bit);
    }else{
        //keep old flagstate if 0 is written
        if(oldval & (1<<udre.bit))
            ref |= (1<<udre.bit);
        else
            ref &= ~(1<<udre.bit);
    }
}

void Uart::onRead(uint32_t addr, uint8_t val)
{
    uint8_t tmp = dataMem->getDirect(rxc.addr);
    dataMem->setDirect(rxc.addr, tmp& ~(1<<rxc.bit) & ~(1<<dor.bit));
}
