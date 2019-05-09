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

#include "Timer.h"

using namespace std;
using namespace std::placeholders;

//TODO: timer dependent prescaler
static const uint32_t presc_table[]={0,1,8,32,64,128,256,1024};

Timer::Timer(MemoryMapper *mapper, timer_registers_t _timer, bool _bit16)
    :PeripheryElement(mapper),timer(_timer),bit16(_bit16)
{
    //callbacks for writing 1 to flags
    dataMem->watchWrite(timer.tov.addr, std::bind(&Timer::onTov,this,_1,_2,_3,_4));
    presc_cnt = 0;
    presc_top = 0;
    timer_top = 0xFF;
    if(bit16) timer_top = 0xFFFF;
}

void Timer::handle(uint32_t cycles)
{
    //fetch configuration
    uint8_t presc = dataMem->getDirect(timer.cs0.addr) & (0x7 << timer.cs0.bit);
    presc_top = timer.presc_table[presc];
    if(presc_top==0)
        return;
    while(cycles--){
        if(++presc_cnt>presc_top){//probably only compare to equalness in hardware
            int32_t count = readReg(timer.tcnt);
            count++;
            if(count>=timer_top){
                count=0;
                uint8_t tmp = dataMem->getDirect(timer.tov.addr);
                tmp |= (1<<timer.tov.bit);
                dataMem->setDirect(timer.tov.addr,tmp);//can be cleared by interrupt or writing one
            }
            writeReg(timer.tcnt,count);
        }
    }
}

void Timer::onTov(uint32_t addr, uint8_t oldval, uint8_t newval, uint8_t &ref)
{
    LOG(Info)<<"timer tov changed: "<<(int)oldval<<" -> "<<(int)newval<<" : "<<(int)ref<<endl;
    //clear flag if 1 is written
    if(newval & (1<<timer.tov.bit)){
        ref &= ~(1<<timer.tov.bit);
    }else{
        //keep old flagstate if 0 is written
        if(oldval & (1<<timer.tov.bit))
            ref |= (1<<timer.tov.bit);
        else
            ref &= ~(1<<timer.tov.bit);
    }
}

