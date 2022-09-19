
#include "../../../LIB/STD_Types.h"
#include "../../../LIB/BIT_MATH.h"
#include "EXTINT2.h"
#include "EXTINT2_cfg.h"
#include "EXTINT2_priv.h"


pf EXTINT2_pfCallback ;

void EXTINT2_voidInit(void)
{

#if EXTINT2_SENSE_MODE == Falling_Edge
	CLR_BIT(MCUCSR , 6) ;

#else
	SET_BIT(MCUCSR , 6) ;
#endif

	CLR_BIT(GICR,5); // Disable External interrupt 0
	SET_BIT(GIFR,5); //Clear External interrupt 0 Flag

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
	EXTINT2_pfCallback = pfCallbackCpy ;
}

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	EXTINT2_pfCallback();
}


