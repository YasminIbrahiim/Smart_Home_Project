
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"
// for ADMUX
#define REFS1 7 // used to select the voltage reference value.
#define REFS0 6
#define ADLAR 5
// for ADCSRA
#define ADEN 7
#define ADSC 6
#define ADATE 5
#define ADIF 4
#define ADIE 3
#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

void Dummy(void);
pf ADC_pfCallback;
uint16 ADC_ReadValue;
void ADC_voidInit(void)
{
#if ADC_VOLTAGE_REFERENCE == AVCC
    CLR_BIT(ADMUX, REFS1);
    SET_BIT(ADMUX, REFS0);
#elif ADC_VOLTAGE_REFERENCE == AREF
    CLR_BIT(ADMUX, REFS1);
    CLR_BIT(ADMUX, REFS0);
#else
    SET_BIT(ADMUX, REFS1);
    SET_BIT(ADMUX, REFS0);
#endif

#if ADC_ADJUSTMENT_MODE == ADC_LEFT
    SET_BIT(ADMUX, ADLAR);
#else
    CLR_BIT(ADMUX, ADLAR);
#endif
    // selecting from ADC0 to ADC 7
    ADMUX |= ADC_CHANNEL_NUM;
// The ADC will start a conversion on a positive edge of the selected trigger signal
#if ADC_AUTO_TRIGGIR_MODE == AUTO_TRIGGIR_ENABLE
    SET_BIT(ADCSRA, ADATE);
    SFIOR |= ADC_AUTO_TRIGGIR_SOURCE;
#else
    CLR_BIT(ADCSRA, ADATE);
#endif
    // setting prescaler value
    ADCSRA |= ADC_PRESCALLER;
    // do nothing if the pointer to function was not assigned an address.
    ADC_pfCallback = Dummy;

    CLR_BIT(ADCSRA, ADIE); /* Disable interrupt  */
    SET_BIT(ADCSRA, ADIF); /* Clear interrupt flag */
}
void ADC_voidEnable(void)
{
    SET_BIT(ADCSRA, ADEN);
}
void ADC_voidDisable(void)
{
    CLR_BIT(ADCSRA, ADEN);
}
void ADC_voidInterruptEnable(void)
{
    SET_BIT(ADCSRA, ADIE);
}
void ADC_voidInterruptDisable(void)
{
    CLR_BIT(ADCSRA, ADIE);
}
void ADC_voidSetCallback(pf pfCallbackCpy)
{
    ADC_pfCallback = pfCallbackCpy;
}
uint16 ADC_u16ReadSync(void)
{
    uint16 u16ReadValueLoc;

    SET_BIT(ADCSRA, ADSC); /*Start conversion */
                           //		flag = 0;

    /*Polling IF */
    // the interrupt flag is set when the conversion ends.

    while (GET_BIT(ADCSRA, ADIF) == 0)
        ;
        //	_delay_us(10);
        //	while(ADCSRA & (1<<ADSC));

#if ADC_ADJUSTMENT_MODE == ADC_LEFT
    u16ReadValueLoc = ADCH;
#else
    u16ReadValueLoc = ADCL | ADCH << 8;
#endif
    SET_BIT(ADCSRA, ADIF); /* Clear event flag */
    return u16ReadValueLoc;
}
void ADC_voidStartConversion(void)
{
    SET_BIT(ADCSRA, 6);
}

uint16 ADC_u16ReadASync(void)
{
    return ADC_ReadValue;
}
float32 ADC_f32NumtoVolt(uint16 u16ReadCpy)
{
    // assuming AREF = VCC
    float32 volt;

    volt = (float32)u16ReadCpy * 5 / 1023;
    return volt;
}
void __vector_16(void) __attribute__((signal, used));
void __vector_16(void)
{

#if ADC_ADJUSTMENT_MODE == ADC_LEFT
    ADC_ReadValue = ADCH;
#else
    ADC_ReadValue = ADCH << 8 | ADCL;
#endif
    ADC_pfCallback();
}

void Dummy(void) {}
