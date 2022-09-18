#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM0.h"
#include "TIM0_cfg.h"
#include "TIM0_priv.h"

pf TIM0_pfCtcCallback ;
pf TIM0_pfOvfCallback ;
static void Delay_Helper(void);
static uint8 u8DelayCounterLOC = 0;

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
	TIM0_pfOvfCallback();
}
/*CM ISR*/
void __vector_10 (void) __attribute__((signal ,used));
void __vector_10 (void)
{
   TIM0_pfCtcCallback();
}
void TIM0_voidDelayMs(uint16 u16DelayTimeCpy)
{
	 uint8 u8PeriodLOC  = (u16DelayTimeCpy / 1000)  /(TIM0_PRESCALLER / CPU_FREQ) / 256;
	 uint8 u8PreloadLOC = 256 -   ( ( (u16DelayTimeCpy / 1000)  /(TIM0_PRESCALLER / CPU_FREQ)) % 256) ;
	 u8DelayCounterLOC = 0;
	
	TIM0_voidSetOvfCallback(Delay_Helper);

	TIM0_voidSetPreloadValue(u8PreloadLOC);
	TIM0_voidEnableOVFIntterrupt();
	if(u8PreloadLOC > 0)
	{
	u8PeriodLOC++;
	}

	while(u8DelayCounterLOC < u8PeriodLOC );

	TIM0_voidDisableOVFIntterrupt();

	        
}

static void Delay_Helper(void)
{
	u8DelayCounterLOC++;
}

uint16 TIM0_u16GetCntrValue(void )
{
	return TCNT0;
}
