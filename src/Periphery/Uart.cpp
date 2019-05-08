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

const int UDRE=5;
const int RXC=7;
const int DOR=3;

Uart::Uart(MemoryMapper *mapper):PeripheryElement(mapper)
{
    dataMem->watchWrite(UDR, std::bind(&Uart::onChange,this,_1,_2,_3,_4));
    dataMem->watchWrite(UCSRA, std::bind(&Uart::onChange,this,_1,_2,_3,_4));
    dataMem->watchRead(UDR, std::bind(&Uart::onRead,this,_1,_2));
    //mapper->watch(UDR);
    //mapper->watch(UCSRA);
    uint8_t tmp = dataMem->getDirect(UCSRA);
    dataMem->setDirect(UCSRA,tmp | (1<<UDRE));
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
                    uint8_t tmp = dataMem->getDirect(UCSRA);
                    if(tmp & (1<<RXC)){
                        dataMem->setDirect(UCSRA,tmp | (1<<DOR));
                        LOG(Info) << "Uart receive overrun: "<< data[0] << std::endl;
                    }else{
                        LOG(Info) << "Uart receive: "<< data[0] << std::endl;
                        dataMem->setDirect(UDR,data[0]);
                        dataMem->setDirect(UCSRA,tmp | (1<<RXC));
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
    if(addr==UDR){
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
        uint8_t tmp = dataMem->getDirect(UCSRA);
        dataMem->setDirect(UCSRA,tmp | (1<<UDRE));
    }else if(addr==UCSRA){
        LOG(Info)<<"UCSRA changed: "<<(int)oldval<<" -> "<<(int)newval<<" : "<<(int)ref<<endl;
        //clear flag if 1 is written
        if(newval & (1<<UDRE)){
            ref &= ~(1<<UDRE);
        }else{
            //keep old flagstate if 0 is written
            if(oldval & (1<<UDRE))
                ref |= (1<<UDRE);
            else
                ref &= ~(1<<UDRE);
        }
    }else{
        LOG(Fatal)<<"Falscher callback"<<endl;
        return;
    }
}

void Uart::onRead(uint32_t addr, uint8_t val)
{
    uint8_t tmp = dataMem->getDirect(UCSRA);
    dataMem->setDirect(UCSRA, tmp& ~(1<<RXC) & ~(1<<DOR));
}
