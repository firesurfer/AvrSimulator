#include "ADC.h"

periphADC::periphADC(MemoryMapper *mapper):
    PeripheryElement (mapper)
{

}

void periphADC::handle(uint32_t cycles)
{
    uint16_t adc = (uint16_t)(voltage * 1024.0f / reference);
    adc = adc & 0x0FFF;
    //dataMem->setDirect16(ADCL,)

    uint8_t admux = memMapper->getData(ADMUX);
}

bool periphADC::isEnabled()
{

}

ADCReference periphADC::getReference()
{

}

ADCPrescaler periphADC::getPrescaler()
{

}

TriggerSource periphADC::getTriggerSource()
{

}

void periphADC::setVoltage(float _voltage)
{
    voltage = _voltage;
}

void periphADC::setExternalReference(float _reference)
{
    reference = _reference;
}
