/********************************************************************************/
/**    File Name: DIO.c                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO  module                             */
/**-----------------------------------------------------------------------------*/
/**  CODING LANGUAGE :  C                                                       */
/**  TARGET          :  Atmega 32                                               */
/**-----------------------------------------------------------------------------*/
/**               C O P Y R I G H T                                             */
/**-----------------------------------------------------------------------------*/
/** Copyright (c) 2022 by ITI .       All rights reserved.                      */
/**                                                                             */
/** This software is copyright protected and proprietary                        */
/** to ITI.                                                                     */
/**-----------------------------------------------------------------------------*/
/**               A U T H O R   I D E N T I T Y                                 */
/**-----------------------------------------------------------------------------*/
/** ShortName    Name                      Company                              */
/** --------     ---------------------     -------------------------------------*/
/** mahmed       Moaz Ahmed Mohamed        ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1      mahmed       Initial Creation                         */
/********************************************************************************/

#include "Std_types.h"
#include "bitManipulation.h"

// mcal
#include "DIO.h" // To be independent on any other file
#include "DIO_cfg.h" 
#include "DIO_priv.h"
// hal
// service
// rte 




/* Description: Scan cfg file and Apply on pins registers the configurations*/
void DIO_voidInit(void)
{
		DDRA = CONC(DIO_u8DIR_PIN_7,DIO_u8DIR_PIN_6,DIO_u8DIR_PIN_5,DIO_u8DIR_PIN_4,DIO_u8DIR_PIN_3,DIO_u8DIR_PIN_2,DIO_u8DIR_PIN_1,DIO_u8DIR_PIN_0);
		DDRB = CONC(DIO_u8DIR_PIN_15,DIO_u8DIR_PIN_14,DIO_u8DIR_PIN_13,DIO_u8DIR_PIN_12,DIO_u8DIR_PIN_11,DIO_u8DIR_PIN_10,DIO_u8DIR_PIN_9,DIO_u8DIR_PIN_8);
		DDRC = CONC(DIO_u8DIR_PIN_23,DIO_u8DIR_PIN_22,DIO_u8DIR_PIN_21,DIO_u8DIR_PIN_20,DIO_u8DIR_PIN_19,DIO_u8DIR_PIN_18,DIO_u8DIR_PIN_17,DIO_u8DIR_PIN_16);
		DDRD = CONC(DIO_u8DIR_PIN_31,DIO_u8DIR_PIN_30,DIO_u8DIR_PIN_29,DIO_u8DIR_PIN_28,DIO_u8DIR_PIN_27,DIO_u8DIR_PIN_26,DIO_u8DIR_PIN_25,DIO_u8DIR_PIN_24);
		
		
}

/* Description: function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31*/
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCPy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK ;
	
	if(u8PinNumCpy >= DIO_u8_PIN_0 && u8PinNumCpy <= DIO_u8_PIN_7 )
	{
		//ODRA
		switch (u8PinValueCPy)
		{
			case DIO_u8HIGH :
				SET_BIT(ODRA , u8PinNumCpy);
			break ;
			case DIO_u8LOW :
				CLR_BIT(ODRA , u8PinNumCpy);
			break ;
			default :
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else if(u8PinNumCpy >= DIO_u8_PIN_8 && u8PinNumCpy <= DIO_u8_PIN_15 )
	{
		// ODRB
		switch (u8PinValueCPy)
		{
			case DIO_u8HIGH :
				SET_BIT(ODRB , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			case DIO_u8LOW :
				CLR_BIT(ODRB , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			default :
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else if(u8PinNumCpy >= DIO_u8_PIN_16 && u8PinNumCpy <= DIO_u8_PIN_23 )
	{
		// ODRC
		switch (u8PinValueCPy)
		{
			case DIO_u8HIGH :
				SET_BIT(ODRC , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			case DIO_u8LOW :
				CLR_BIT(ODRC , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			default :
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else if(u8PinNumCpy >= DIO_u8_PIN_24 && u8PinNumCpy <= DIO_u8_PIN_31 )
	{
		// ODRD
		switch (u8PinValueCPy)
		{
			case DIO_u8HIGH :
				SET_BIT(ODRD , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			case DIO_u8LOW :
				CLR_BIT(ODRD , u8PinNumCpy % DIO_u8PIN_SIZE);
			break ;
			default :
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
	}
	
	return enuReturnStautsLoc ;
}
/* Description: function to read the value on the pins (0 or 1) starting from pin 0 to pin 31*/
tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy, uint8 * pu8PinValueCpy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	
	if(pu8PinValueCpy != NULL_PTR)
	{
		if(u8PinNumCpy >= DIO_u8_PIN_0 && u8PinNumCpy <= DIO_u8_PIN_7 )
		{
			*pu8PinValueCpy = GET_BIT(IDRA , u8PinNumCpy);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_8 && u8PinNumCpy <= DIO_u8_PIN_15 )
		{
			*pu8PinValueCpy = GET_BIT(IDRB , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_16 && u8PinNumCpy <= DIO_u8_PIN_23)
		{
			*pu8PinValueCpy = GET_BIT(IDRC , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_24 && u8PinNumCpy <= DIO_u8_PIN_31)
		{
			*pu8PinValueCpy = GET_BIT(IDRD , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else
		{
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_NULL_POINTER;
	}
	return enuReturnStautsLoc;	
}

/* Description: function to activate the pull up register on a specific pin*/

tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy)
{
	return DIO_enuWritePin(u8PinNumCpy , u8PinStateCpy);
}

/* Description: function to write on several pins in the same time*/

tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	uint8 u8CntrLoc ; 
	if(pastrPinMappingCpy != NULL_PTR)
	{	
		if(u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS)
		{
		
			for(u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc].enuStatus = DIO_enuWritePin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , pastrPinMappingCpy[u8CntrLoc].u8PinValue);
			
			}
		}
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_NULL_POINTER;
	}
	return enuReturnStautsLoc;
}

/* Description: function to read the values on several pins*/

tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	uint8 u8CntrLoc ; 
	if(pastrPinMappingCpy != NULL_PTR)
	{	
		if(u8SizeCpy <= DIO_u8MAX_NUMBER_OF_PINS)
		{
			for(u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
			{
				pastrPinMappingCpy[u8CntrLoc].enuStatus = DIO_enuReadPin(pastrPinMappingCpy[u8CntrLoc].u8PinNum , &(pastrPinMappingCpy[u8CntrLoc].u8PinValue));
			}
		}
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_NULL_POINTER;
	}
	return enuReturnStautsLoc ;
	
}

/* Description: function to set the direction of specofic pin DIO_u8OUTPUT or DIO_u8INPUT*/

tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	switch(u8PinDirCpy)
	{
		case DIO_u8OUTPUT:
			if(u8PinNumCpy >= DIO_u8_PIN_0 && u8PinNumCpy <= DIO_u8_PIN_7 )
			{
				SET_BIT(DDRA,u8PinNumCpy);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_8 && u8PinNumCpy <= DIO_u8_PIN_15 )
			{
				SET_BIT(DDRB,u8PinNumCpy % 8);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_16 && u8PinNumCpy <= DIO_u8_PIN_23)
			{
				SET_BIT(DDRC,u8PinNumCpy % 8);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_24 && u8PinNumCpy <= DIO_u8_PIN_31)
			{
				SET_BIT(DDRD,u8PinNumCpy % 8);
			}
			else
			{
				enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
			}
		break;
		case DIO_u8INPUT:
			if(u8PinNumCpy >= DIO_u8_PIN_0 && u8PinNumCpy <= DIO_u8_PIN_7 )
			{
				CLR_BIT(DDRA,u8PinNumCpy);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_8 && u8PinNumCpy <= DIO_u8_PIN_15 )
			{
				CLR_BIT(DDRB,u8PinNumCpy % 8);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_16 && u8PinNumCpy <= DIO_u8_PIN_23)
			{
				CLR_BIT(DDRC,u8PinNumCpy % 8);
			}
			else if(u8PinNumCpy >= DIO_u8_PIN_24 && u8PinNumCpy <= DIO_u8_PIN_31)
			{
				CLR_BIT(DDRD,u8PinNumCpy % 8);
			}
			else
			{
				enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
			}
		break;
		default:
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		break;
	}
	return enuReturnStautsLoc;
}

/* Description: function to toogle the state of specific LED*/
tenuErrorStatus DIO_enuTogglePin(uint8 u8LedMappingCpy)
{
	
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	if(u8LedMappingCpy >= DIO_u8_PIN_0 && u8LedMappingCpy <= DIO_u8_PIN_7 )
	{
		TGL_BIT(ODRA , u8LedMappingCpy);
	}
	else if(u8LedMappingCpy >= DIO_u8_PIN_8 && u8LedMappingCpy <= DIO_u8_PIN_15 )
	{
		TGL_BIT(ODRB , u8LedMappingCpy % DIO_u8PIN_SIZE);
	}
	else if(u8LedMappingCpy >= DIO_u8_PIN_16 && u8LedMappingCpy <= DIO_u8_PIN_23)
	{
		TGL_BIT(ODRC , u8LedMappingCpy % DIO_u8PIN_SIZE);
	}
	else if(u8LedMappingCpy >= DIO_u8_PIN_24 && u8LedMappingCpy <= DIO_u8_PIN_31)
	{
		TGL_BIT(ODRD , u8LedMappingCpy % DIO_u8PIN_SIZE);
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
	}
	
	return enuReturnStautsLoc;
}




tenuErrorStatus DIO_enuReadPinDir(uint8 u8PinNumCpy, uint8 * pu8PinValueCpy)
{
	tenuErrorStatus enuReturnStautsLoc = E_OK;
	
	if(pu8PinValueCpy != NULL_PTR)
	{
		if(u8PinNumCpy >= DIO_u8_PIN_0 && u8PinNumCpy <= DIO_u8_PIN_7 )
		{
			*pu8PinValueCpy = GET_BIT(DDRA , u8PinNumCpy);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_8 && u8PinNumCpy <= DIO_u8_PIN_15 )
		{
			*pu8PinValueCpy = GET_BIT(DDRB , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_16 && u8PinNumCpy <= DIO_u8_PIN_23)
		{
			*pu8PinValueCpy = GET_BIT(DDRC , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else if(u8PinNumCpy >= DIO_u8_PIN_24 && u8PinNumCpy <= DIO_u8_PIN_31)
		{
			*pu8PinValueCpy = GET_BIT(DDRD , u8PinNumCpy % DIO_u8PIN_SIZE);
		}
		else
		{
			enuReturnStautsLoc = E_NOK_PARAM_OUT_OF_RANGE;
		}
	}
	else
	{
		enuReturnStautsLoc = E_NOK_PARAM_NULL_POINTER;
	}
	return enuReturnStautsLoc;
}







