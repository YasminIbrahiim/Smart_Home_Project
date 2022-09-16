#include "STD_Types.h"
#include "BIT_Math.h"
#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

pf TIM2_pfCtcCallback;
pf TIM2_pfOvfCallback;
volatile static uint8 u8DelayCounter;

static void Delay_Helper(void);

void TIM2_VoidInit(void)
{
	uint8 u8TempLOC;
	/* Disable timer interrupts */
	CLR_BIT(TIMSK, 6);
	CLR_BIT(TIMSK, 7);

	#if   TIMER2_MODE == TIM2_NORMAL_MODE
	u8TempLOC =  (0x80);	      
	#elif TIMER2_MODE ==TIM2_PWM_PHASE_CORRECT_MODE
	u8TempLOC =  (0xC0);        
	#elif TIMER2_MODE ==TIM2_CTC_MODE
	u8TempLOC =  (0x88);                           
	#else
	u8TempLOC =  (0xC8);                   
	#endif

	#if TIMER2_CLK_SOURCE == ASYNC_MODE
	/* Enable ASYNC mode */
	SET_BIT(ASSR, 3);
	
	while(GET_BIT(ASSR, 0));
	TCCR2 = u8TempLOC | TIMER2_PRESCALER ; 
	#else
	CLR_BIT(ASSR, 3);
	TCCR2 = u8TempLOC | TIMER2_PRESCALER ;
	#endif
	/* clear interrupt flags */
	SET_BIT(TIFR, 6);
	SET_BIT(TIFR, 7);

	
}

void TIM2_VoidSetPreloadValue(uint8 u8PreloadValueCpy)
{
	#if TIMER2_CLK_SOURCE == ASYNC_MODE
	/* check if TCNT2 is ready to be updated */
	while(GET_BIT(ASSR, 2));
	TCNT2 = u8PreloadValueCpy ;
 
	#else
	TCNT2 = u8PreloadValueCpy ;	
	#endif

}

void TIM2_voidSetOutputCompareValue(uint8 u8LoadValueCpy)
{
	#if TIMER2_CLK_SOURCE == ASYNC_MODE
	/* check if OCR2 is ready to be updated */
	while(GET_BIT(ASSR, 1));
	OCR2 = u8LoadValueCpy;  
	#else
	OCR2 = u8LoadValueCpy; 
	#endif
}

void TIM2_VoidEnableOVFInterrupt(void)
{
	SET_BIT(TIMSK , 6);
}

void TIM2_VoidDisableOVFInterrupt(void)
{
	CLR_BIT(TIMSK , 6);
}

void TIM2_VoidEnableCTCInterrupt(void)
{
	SET_BIT(TIMSK , 7);
}

void TIM2_VoidDisableCTCInterrupt(void)
{
	CLR_BIT(TIMSK , 7);
}

void TIM2_VoidSetOVFCallback(pf pfOVFCallbackCpy)
{
	TIM2_pfOvfCallback = pfOVFCallbackCpy; 

}

void TIM2_VoidSetCTCCallback(pf pfCTCCallbackCpy)
{
	TIM2_pfCtcCallback = pfCTCCallbackCpy;
}

void TIM2_VoidDelayMs(uint16 u16DelayTimeCpy)
{
	
	uint8 u8PeriodLOC  = (u16DelayTimeCpy / 1000)  /(TIMER2_PRESCALER / CPU_FREQ) / 256;
	uint8 u8PreloadLOC = 256 -  ( ( (u16DelayTimeCpy / 1000)  /(TIMER2_PRESCALER / CPU_FREQ)) % 256) ;
	u8DelayCounter = 0;
	
	TIM2_VoidSetOVFCallback(Delay_Helper);

	TIM2_VoidSetPreloadValue(u8PreloadLOC);
	TIM2_VoidEnableOVFInterrupt();
	if(u8PreloadLOC > 0)
	{
	u8PeriodLOC++;
	}

	while(u8DelayCounter < u8PeriodLOC );
	        
}

static void Delay_Helper(void)
{
	u8DelayCounter++;
}
void __vector_5(void) __attribute__((signal,used));
void __vector_5(void)
{
	TIM2_pfOvfCallback();	
}

void __vector_4(void) __attribute__((signal,used));
void __vector_4(void)
{
	TIM2_pfCtcCallback();
}





