#include "Uart.h"

using namespace std;
using namespace std::placeholders;

const int UDRE=5;

Uart::Uart(MemoryMapper *mapper):PeripheryElement(mapper)
{
    mapper->watch(UDR, std::bind(&Uart::onChange,this,_1,_2,_3,_4));
    mapper->watch(UCSRA, std::bind(&Uart::onChange,this,_1,_2,_3,_4));
    //mapper->watch(UDR);
    //mapper->watch(UCSRA);
    uint8_t tmp = mem_mapper->getData(UCSRA);
    mem_mapper->getDataMemory()->Set(UCSRA,tmp | (1<<UDRE),false);
}

void Uart::handle(uint32_t cycles)
{
}

void Uart::onChange(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref)
{
    if(addr==UDR){
        ref=oldval;//dont change UDR because its also the rescieve register
        LOG(Info)<<"Uart: '"<<newval<<"'"<<endl;
        if(newval=='\n'){
            LOG(Important)<<"UART: "<<buffer<<endl;
            buffer="";
        }else
            buffer+=newval;
        uint8_t tmp = mem_mapper->getData(UCSRA);
        mem_mapper->getDataMemory()->Set(UCSRA,tmp | (1<<UDRE),false);
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
