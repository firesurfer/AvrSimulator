#include "Uart.h"

using namespace std;
using namespace std::placeholders;

const int UDRE=5;

Uart::Uart(MemoryMapper *mapper):PeripheryElement(mapper)
{
    mapper->watch(UDR, std::bind(&Uart::onChange,this,_1,_2,_3));
    //mapper->watch(UDR);
    //mapper->watch(UCSRA);
}

void Uart::handle(uint32_t cycles)
{
    uint8_t tmp = mem_mapper->getData(UCSRA);
    mem_mapper->setData(UCSRA,tmp | (1<<UDRE));
}

void Uart::onChange(uint32_t addr, uint8_t oldval, uint8_t newval)
{
    if(addr!=UDR){
        LOG(Fatal)<<"Falscher callback"<<endl;
        return;
    }
    LOG(Info)<<"Uart: '"<<newval<<"'"<<endl;
    if((mem_mapper->getData(UCSRA)>>UDRE) & 1){
        if(newval=='\n'){
            LOG(Important)<<"UART: "<<buffer<<endl;
            buffer="";
        }else
            buffer+=newval;
    }

}
