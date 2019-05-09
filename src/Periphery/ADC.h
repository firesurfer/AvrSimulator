#ifndef ADC_H
#define ADC_H

#include "PeripheryElement.h"

enum class ADCReference
{
    AREF,
    AVCC,
    INTERNAL,
    RESERVED
};

enum class ADCPrescaler
{
    Scale2,
    Scale4,
    Scale8,
    Scale16,
    Scale32,
    Scale64,
    Scale128
};

enum class TriggerSource
{
    FreeRunning,
    AnalogComparator,
    ExternalInterrupt0,
    Timer0CompareMatch,
    Timer0Overflow,
    Timer1CompareMatchB,
    Timer1Overflow,
    Timer1CaptureEvent
};

class ADC: public PeripheryElement
{
public:
    ADC(MemoryMapper* mapper);
    virtual void handle(uint32_t cycles);
    ADCReference getReference();
    ADCPrescaler getPrescaler();
    TriggerSource getTriggerSource();
    void setVoltage(float _voltage);
    void setExternalReference(float _reference);
private:
    bool isEnabled();


    float voltage = 0.0f;
    float reference = 5.0;
};

#endif // ADC_H
