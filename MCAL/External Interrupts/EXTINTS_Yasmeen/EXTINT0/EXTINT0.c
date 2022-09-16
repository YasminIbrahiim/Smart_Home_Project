
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT0.h"
#include "EXTINT0_cfg.h"
#include "EXTINT0_priv.h"


pf EXTINT0_pfCallback ;

void EXTINT0_voidInit(void)
{

	CLR_BIT(GICR,6); // Disable External interrupt 0
	SET_BIT(GIFR,6); //Clear External interrupt 0 Flag

}

void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR,6);
}

void EXTINT0_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT0_pfCallback = pfCallbackCpy ;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTINT0_pfCallback();
	SET_BIT(GIFR,6);
}

void EXTINT0_voidSetSenseValue(uint8 u8SenseValueCpy)
{
	if(u8SenseValueCpy == LOW_LEVEL)
	{
		CLR_BIT(MCUCR , 0) ;
		CLR_BIT(MCUCR , 1) ;
	}else if(u8SenseValueCpy == IOC)
	{
		SET_BIT(MCUCR , 0) ;
		CLR_BIT(MCUCR , 1) ;
	}else if(u8SenseValueCpy == FALLING_EDGE )
	{
		CLR_BIT(MCUCR , 0) ;
	    SET_BIT(MCUCR , 1) ;
	}else if(u8SenseValueCpy == RISING_EDGE )
	{
		SET_BIT(MCUCR , 0) ;
	    SET_BIT(MCUCR , 1) ;
	}else
	{
		CLR_BIT(MCUCR , 0) ;
		CLR_BIT(MCUCR , 1) ;
	}
		

}
