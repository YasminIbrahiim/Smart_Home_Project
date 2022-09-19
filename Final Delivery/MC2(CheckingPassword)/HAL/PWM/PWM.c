#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "TIM0.h"
#include "TIM2.h"
#include "PWM.h"
#include "PWM_cfg.h"
#include "PWM_priv.h"

uint32 u32PeriodHighLOC;
uint8  u8PreloadHighLOC;
uint32 u32PeriodLowLOC;
uint8 u8PreloadLOWLOC;
volatile uint32 u32CountsHigh = 0;
volatile uint32 u32CountsLow = 0;
static void HelperSetLow(void);
static void HelperSetHigh(void);

void PWM_VoidFreq_DutyCycleCtrl(uint32 f32FreqValueCpy , uint32 u32DutyCycleValueCpy)
{


	u32PeriodHighLOC  =  8000000  /(f32FreqValueCpy * 8 *256) ;

	u8PreloadHighLOC = (256 - ( 8000000  /(f32FreqValueCpy * 8)) % 256 )   ;

	u32PeriodLowLOC   =  (u32DutyCycleValueCpy * 8000000)  /(100  * f32FreqValueCpy * 8 *256)  ;
	u8PreloadLOWLOC     = 256 - (( (u32DutyCycleValueCpy * 8000000)  /(100  * f32FreqValueCpy * 8) )% 256 );
	u32CountsHigh = 0;
	u32CountsLow = 0;

	if(u8PreloadHighLOC > 0)
	{
		u32PeriodHighLOC++;
	}
	if(u8PreloadLOWLOC > 0)
	{
		u32PeriodLowLOC++;
	}
	if(u32CountsHigh == 0 )
	{
		TIM0_voidSetPreloadValue(u8PreloadHighLOC);
	}
	if(u32CountsLow == 0 )
	{
		TIM2_VoidSetPreloadValue(u8PreloadLOWLOC);
	}
	TIM0_voidSetOvfCallback(HelperSetHigh);
	TIM2_VoidSetOVFCallback(HelperSetLow);
	TIM0_voidEnableOVFIntterrupt();
	TIM2_VoidEnableOVFInterrupt();

}

static void HelperSetHigh(void)
{

	u32CountsHigh++;
	if(u32CountsHigh == u32PeriodHighLOC )
	{
		u32CountsHigh = 0;
		u32CountsLow = 0;
		DIO_enuWritePin(PWM_PIN,DIO_u8HIGH  );
		TIM0_voidSetPreloadValue(u8PreloadHighLOC);
		TIM2_VoidSetPreloadValue(u8PreloadLOWLOC);
	}
}

static void HelperSetLow(void)
{
	//DIO_enuWritePin(DIO_u8PIN_4,DIO_u8HIGH  );
	u32CountsLow++;
	if(u32CountsLow == u32PeriodLowLOC)
	{
		DIO_enuWritePin(PWM_PIN , DIO_u8LOW  );

	}
}
