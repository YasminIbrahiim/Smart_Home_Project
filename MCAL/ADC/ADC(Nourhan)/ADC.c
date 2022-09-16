
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "ADC.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"

void Dummy(void);
pf ADC_pfCallback  ;
uint16 ADC_ReadValue ;
void ADC_voidInit(void)
{
	#if ADC_VOLTAGE_REFERENCE   == AVCC
	  CLR_BIT(ADMUX  , 7 );
	  SET_BIT(ADMUX , 6 );
	#elif ADC_VOLTAGE_REFERENCE == AREF
	  CLR_BIT(ADMUX  , 7 );
	  CLR_BIT(ADMUX  , 6 );
	#else 
	  SET_BIT(ADMUX , 7 );
	  SET_BIT(ADMUX , 6 );
	#endif 
	
	#if ADC_ADJUSTMENT_MODE == ADC_LEFT
	  SET_BIT(ADMUX , 5 );
	#else 
	  CLR_BIT(ADMUX , 5 );
	#endif 
	
	ADMUX |= ADC_CHANNEL_NUM;
	
	#if ADC_AUTO_TRIGGIR_MODE == AUTO_TRIGGIR_ENABLE 
		SET_BIT(ADCSRA , 5);
	    SFIOR |= ADC_AUTO_TRIGGIR_SOURCE ;
	#else 
		CLR_BIT(ADCSRA , 5);
	#endif 
	
	ADCSRA |= ADC_PRESCALLER ;
	ADC_pfCallback = Dummy ;
	CLR_BIT(ADCSRA , 3 ); /* Disable interrupt  */
	SET_BIT(ADCSRA , 4 ); /* Clear interrupt flag */
}                                  
void ADC_voidEnable(void)         
{
	SET_BIT(ADCSRA , 7 );
}
void ADC_voidDisable(void)
{
	CLR_BIT(ADCSRA , 7 );
}
void ADC_voidInterruptEnable(void)
{
	SET_BIT(ADCSRA , 3 );
}
void ADC_voidInterruptDisable(void)
{
	CLR_BIT(ADCSRA , 3 );
}
void ADC_voidSetCallback(pf pfCallbackCpy ) 
{
	ADC_pfCallback = pfCallbackCpy ;
}
uint16 ADC_u16ReadSync(void)
{
	uint16 u16ReadValueLoc ;
	SET_BIT(ADCSRA , 6 ) ; /*Start conversion */
	/*Polling IF */
	while (GET_BIT(ADCSRA , 4) == 0);
	SET_BIT(ADCSRA,4); /* Clear event flag */
	
	#if ADC_ADJUSTMENT_MODE  == ADC_LEFT
	u16ReadValueLoc = ADCH ;
	#else
	u16ReadValueLoc = ADCH<<8 | ADCL;
	#endif
	
	return u16ReadValueLoc ; 
	
}
void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA , 6 ) ;
}

uint16 ADC_u16ReadASync(void)
{
	return ADC_ReadValue ;
}

void __vector_16 (void) __attribute__((signal,used));
void __vector_16 (void)
{
	 
	#if ADC_ADJUSTMENT_MODE  == ADC_LEFT
	 ADC_ReadValue = ADCH  ; 
	#else
	ADC_ReadValue = ADCH<<8 | ADCL;
	#endif
	ADC_pfCallback();
}

void Dummy(void){}
