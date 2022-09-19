#include "../../../LIB/STD_Types.h"
#include "../../../LIB/BIT_MATH.h"

#include "TIM0.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

pf TIM0_pfCtcCallback ;
pf TIM0_pfOvfCallback ;
uint8 delay =0;
uint32 msec =0;
void TIM0_voidInit(void)
{
	#if   TIM0_MODE == TIM0_NORMAL_MODE 
		CLR_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
	#elif TIM0_MODE == TIM0_PWM_PHASE_CORRECT_MODE
		SET_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
   #elif TIM0_MODE == TIM0_CTC_MODE 
		CLR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
   #else
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
   #endif
  
  TCCR0 &= (0xF8);/* clear reg 0b1111 1000 */
  TCCR0 |=((0x03)& TIM0_PRESCALLER) ; /* write in reg */

 TCNT0 = 0;
 OCR0  = 0;
 /* Disable Interrupt  OVF CM */
 CLR_BIT(TIMSK , 0) ;
 CLR_BIT(TIMSK , 1) ;
 /* Clear IF flags OVF CM */
 SET_BIT(TIFR  , 0) ;
 SET_BIT(TIFR  , 1) ;

}
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT0 = u8PreloadValueCpy;
}
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR0 = u8LoadValueCpy; 
}
void TIM0_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 0) ;
}
void TIM0_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 0) ;
}
void TIM0_voidEnableCTCIntterrupt(void)
{
		SET_BIT(TIMSK , 1) ;
}
void TIM0_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 1) ;
}
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM0_pfOvfCallback = pfOvfCallbackCpy ;
}
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy)
{
	TIM0_pfCtcCallback = pfCtcCallbackCpy;
}
/*OVF ISR*/
void __vector_11 (void) __attribute__((signal ,used));
void __vector_11 (void)
{
	static uint32 counter = 0;
	counter++;

	TIM0_pfOvfCallback();
}
/*CM ISR*/
void __vector_10 (void) __attribute__((signal ,used));
void __vector_10 (void)
{
	static uint32 counter = 0;
	counter++;

	if( counter == msec && delay == 1){
			counter=0;
			TIM0_pfCtcCallback();

	}
	else if(delay == 0)
	{
		TIM0_pfCtcCallback();
	}

}
void TIM0_voidDelayMs(uint16 u16DalayTimeCpy)
{
	TIM0_voidSetOutputCompareValue(250);
	delay =1;
	msec = 4 *u16DalayTimeCpy;

}

uint16 TIM0_u16GetCntrValue(void)
{
	return (uint16)TCNT0;
}

void TIM0_voidFPWMInit(void){

#if TIM0_PWM_MODE == TIM0_Non_PWM_OFF

#define TIM0_MODE    TIM0_Non_PWM_OFF
	TIM0_voidInit();

	CLR_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

#elif TIM0_PWM_MODE == TIM0_Non_PWM_TGL

#define TIM0_MODE    TIM0_Non_PWM_OFF
	TIM0_voidInit();

	SET_BIT(TCCR0,4);
	CLR_BIT(TCCR0,5);

#elif TIM0_PWM_MODE == TIM0_Non_PWM_CLR

#define TIM0_MODE    TIM0_Non_PWM_OFF
	TIM0_voidInit();

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_PWM_MODE == TIM0_Non_PWM_Set

#define TIM0_MODE    TIM0_Non_PWM_OFF
	TIM0_voidInit();

	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);

#elif TIM0_PWM_MODE == TIM0_Fast_PWM_CLR

#define TIM0_MODE    TIM0_FAST_PWM_MODE
	TIM0_voidInit();

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIM0_PWM_MODE == TIM0_Fast_PWM_SET

#define TIM0_MODE    TIM0_FAST_PWM_MODE
	TIM0_voidInit();

	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#elif TIM0_PWM_MODE == TIM0_PHC_PWM_CLR_UPCNT

#define TIM0_MODE    TIM0_PWM_PHASE_CORRECT_MODE
	TIM0_voidInit();

	CLR_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#else

#define TIM0_MODE    TIM0_PWM_PHASE_CORRECT_MODE
	TIM0_voidInit();

	SET_BIT(TCCR0,4);
	SET_BIT(TCCR0,5);
#endif


}

