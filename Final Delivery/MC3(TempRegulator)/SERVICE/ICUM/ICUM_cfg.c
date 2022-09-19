#include "../../LIB/STD_Types.h"

#include "../../MCAL/EXTINT/EXTINT0/EXTINT0.h"
#include "../../MCAL/EXTINT/EXTINT1/EXTINT1.h"

#include "../../MCAL/TIM/TIM0/TIM0.h"
#include "../../MCAL/TIM/TIM2/TIM2.h"

#include "ICUM.h"
#include "ICUM_cfg.h"
#include "ICUM_priv.h"




void EXTINT0_voidSetSenseValue(uint8 u8SenseValueCpy);
void EXTINT1_voidSetSenseValue(uint8 u8SenseValueCpy);
uint16 TIM0_u16GetCntrValue(void );
uint16 TIM2_u16GetCntrValue(void );

tstrIcuCfg ICUM_apfConfigSet[2]=
{
	/* Varient 1*/
	{
		EXTINT0_voidSetCallBack , TIM0_voidSetOvfCallback,
		TIM0_u16GetCntrValue    , EXTINT0_voidSetSenseValue,
		256                     , 8000000
	
	
	},
	
	
	/* Varient 2*/
	{
		EXTINT1_voidSetCallBack , TIM2_voidSetOvfCallback   ,
		TIM2_u16GetCntrValue    , EXTINT1_voidSetSenseValue ,
		256                     , 1000000
	}	
};


