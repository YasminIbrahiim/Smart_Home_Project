/*************************************************/
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "EXTINT1.h"
#include "EXTINT1_cfg.h"
#include "EXTINT1_priv.h"


pf EXTINT1_pfcallback;

void EXTINT1_voidInit(void)
{
	SET_BIT(GIFR , 7);
	CLR_BIT(GICR , 7);

}

void EXTINT1_voidEnable(void)
{
	SET_BIT(GICR , 7);
}

void EXTINT1_voidDisable(void)
{
	CLR_BIT(GICR , 7);
}


void EXTINT1_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT1_pfcallback = pfCallbackCpy;
}
void __vector_2(void) __attribute__((signal,used));

void __vector_2(void)
{
	EXTINT1_pfcallback();
	SET_BIT(GIFR,7);
}

void EXTINT1_voidSetSenseValue(uint8 u8SenseValueCpy)
{
	if(u8SenseValueCpy == LOW_LEVEL)
	{
		CLR_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
	}else if(u8SenseValueCpy == LOC)
	{
		SET_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
	}else if(u8SenseValueCpy == FALLING_EDGE )
	{
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}else if(u8SenseValueCpy == RISING_EDGE )
	{
		CLR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
	}else
	{
		CLR_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
	}
		
}