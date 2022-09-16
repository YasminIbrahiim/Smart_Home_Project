/*************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "EXTINT2.h"
#include "EXTINT2_cfg.h"
#include "EXTINT2_priv.h"


pf EXTINT2_pfcallback;

void EXTINT2_voidInit(void)
{
	SET_BIT(GIFR , 5);
	CLR_BIT(GICR , 5);
	
	#if EXTINT2_SENSE_MODE == RISING_EDGE
	SET_BIT(MCUCSR , 6);
	
	#else
	CLR_BIT(MCUCSR , 6);
	
	#endif 
}

void EXTINT2_voidEnable(void)
{
	SET_BIT(GICR , 5);
}

void EXTINT2_voidDisable(void)
{
	CLR_BIT(GICR , 5);
}


void EXTINT2_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT2_pfcallback = pfCallbackCpy;
}
void __vector_3(void) __attribute__((signal,used));

void __vector_3(void)
{
	EXTINT2_pfcallback();
	SET_BIT(GIFR , 5);
}
