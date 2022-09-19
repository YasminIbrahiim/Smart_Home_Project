
#include "../../../LIB/STD_Types.h"
#include "../../../LIB/BIT_MATH.h"
#include "EXTINT1.h"
#include "EXTINT1_cfg.h"
#include "EXTINT1_priv.h"


pf EXTINT1_pfCallback ;

void EXTINT1_voidInit(void)
{

#if EXTINT0_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;

#elif EXTINT1_SENSE_MODE ==IOC
	SET_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;
#elif EXTINT1_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#else
	SET_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#endif

	CLR_BIT(GICR,7); // Disable External interrupt 0
	SET_BIT(GIFR,7); //Clear External interrupt 0 Flag

}

void EXTINT1_voidEnable(void)
{
	SET_BIT(GICR,7);
}

void EXTINT1_voidDisable(void)
{
	CLR_BIT(GICR,7);
}

void EXTINT1_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT1_pfCallback = pfCallbackCpy ;
}

void EXTINT1_voidSetSenseValue(uint8 u8SenseValueCpy)
{
	switch(u8SenseValueCpy)
	{
		case FALLING_EDGE:
			CLR_BIT(MCUCR,2) ;
			SET_BIT(MCUCR,3) ;
		break;
		case RISING_EDGE:
			SET_BIT(MCUCR,2) ;
			SET_BIT(MCUCR,3) ;
		break;

	}
}

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	EXTINT1_pfCallback();
}


