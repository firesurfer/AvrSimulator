#include "ADC.h"

ADC::ADC(MemoryMapper *mapper):
    PeripheryElement (mapper)
{

}

void ADC::handle(uint32_t cycles)
{
    uint16_t adc = (uint16_t)(voltage * 1024.0f / reference);
    adc = adc & 0x0FFF;
    //dataMem->setDirect16(ADCL,)

    uint8_t admux = memMapper->getData(ADMUX);
}

bool ADC::isEnabled()
{

}

ADCReference ADC::getReference()
{

}

ADCPrescaler ADC::getPrescaler()
{

}

TriggerSource ADC::getTriggerSource()
{

}

void ADC::setVoltage(float _voltage)
{
    voltage = _voltage;
}

void ADC::setExternalReference(float _reference)
{
    reference = _reference;
}
