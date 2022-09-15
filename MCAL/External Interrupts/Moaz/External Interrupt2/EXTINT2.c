

#include "Std_types.h"
#include "bitManipulation.h"


#include "EXTINT2.h"
#include "EXTINT2_cfg.h"
#include "EXTINT2_priv.h"


pf EXTINT2_pfCallback;

void EXTINT2_voidInit(void)
{
#if EXTINT2_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR,6) ; 
#elif EXTINT2_SENSE_MODE == RISING
	SET_BIT(MCUCSR,6) ; 
#endif
	CLR_BIT(GICR,5); // Disable External Unterrupt 2
	SET_BIT(GIFR,5); // Clear External interrupt 2 flag
}


void EXTINT2_voidEnable(void)
{
	SET_BIT(GICR,5);
}


void EXTINT2_voidDisable(void)
{
	CLR_BIT(GICR,5);
}

void EXTINT2_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT2_pfCallback = pfCallbackCpy;
}



void  __vector_3(void) __attribute__((signal,used)); // It is volatile called by hardware not software
void  __vector_3(void)
{
	
	EXTINT2_pfCallback();
}
