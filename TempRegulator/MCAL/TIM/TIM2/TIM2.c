
#include "../../../LIB/STD_Types.h"
#include "../../../LIB/BIT_Math.h"

#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"


pf TIM2_pfCtcCallback ;
pf TIM2_pfOvfCallback ;

void TIM2_voidInit(void)
{
	#if   TIM2_MODE == TIM2_NORMAL_MODE 
		CLR_BIT(TCCR2 , 6);
		CLR_BIT(TCCR2 , 3);
	#elif TIM2_MODE == TIM2_PWM_PHASE_CORRECT_MODE
		SET_BIT(TCCR2 , 6);
		CLR_BIT(TCCR2 , 3);
   #elif TIM2_MODE == TIM2_CTC_MODE 
		CLR_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
   #else
		SET_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
   #endif
   
   
	TCCR2 &= (0xF8);/* clear reg 0b1111 1000 */
	TCCR2 |=((0x03) & TIM2_PRESCALLER) ; /* write in reg */
  
	TCNT2 = 0;
	OCR2  = 0;
	/* Disable Interrupt  OVF CM */
	CLR_BIT(TIMSK , 6) ;
	CLR_BIT(TIMSK , 7) ;
	/* Clear IF flags OVF CM */
	SET_BIT(TIFR  , 6) ;
	SET_BIT(TIFR  , 7) ;
}
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT2 = u8PreloadValueCpy;
}
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR2 = u8LoadValueCpy;
}
void TIM2_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 6) ;
}
void TIM2_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 6) ;
}
void TIM2_voidEnableCTCIntterrupt(void)
{
	SET_BIT(TIMSK , 7) ;
}
void TIM2_voidDisableCTCIntterrupt(void)
{
	CLR_BIT(TIMSK , 7) ;
}
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	pfOvfCallbackCpy = TIM2_pfOvfCallback;
}
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy)
{
	pfCtcCallbackCpy = TIM2_pfCtcCallback;
}

uint16 TIM2_u16GetCntrValue(void)
{
	return (uint16)TCNT2;
}

/*OVF ISR*/
void __vector_5 (void) __attribute__((signal ,used));
void __vector_5 (void)
{
	TIM2_pfOvfCallback();
}
/*CM ISR*/
void __vector_4 (void) __attribute__((signal ,used));
void __vector_4 (void)
{
   TIM2_pfCtcCallback();
}

void TIM2_voidDelayMs(uint16 u16DalayTimeCpy)
{
	
}

