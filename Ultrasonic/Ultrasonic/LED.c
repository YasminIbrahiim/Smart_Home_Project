/********************************************************************************/
/**    File Name: LED.h                                                         */
/**                                                                             */
/**  Description: Implementation of the LED contain configuration for the module*/
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
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 22/08/2022   0.1       aaboelno     Initial Creation                        */
/********************************************************************************/
#include "STD_Types.h"

#include "DIO.h"

#include "LED.h"
#include "LED_cfg.h"
#include "LED_priv.h"


tenuErrorStatus LED_enuWriteValue (uint8 u8LedNumCpy , uint8 u8LedValueCpy  )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if (u8LedNumCpy < LED_MAX_NUM )
	{
		switch(u8LedValueCpy)
		{
			case LED_u8ON :
				if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8NORMAL)
				{
					enuReturnStatLoc = DIO_enuWritePin(LED_astrLedPinMapping[u8LedNumCpy].u8DioPinMap , DIO_u8HIGH ) ;
				}
				else if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8REVERSE)
				{
					enuReturnStatLoc = DIO_enuWritePin(LED_astrLedPinMapping[u8LedNumCpy].u8DioPinMap , DIO_u8LOW ) ;			
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}
			break ;
			case LED_u8OFF:
			   if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8NORMAL)
				{
					enuReturnStatLoc = DIO_enuWritePin(LED_astrLedPinMapping[u8LedNumCpy].u8DioPinMap , DIO_u8LOW ) ;
				}
				else if (LED_astrLedPinMapping[u8LedNumCpy].u8LedModeConc == LED_u8REVERSE)
				{
					enuReturnStatLoc = DIO_enuWritePin(LED_astrLedPinMapping[u8LedNumCpy].u8DioPinMap , DIO_u8HIGH ) ;			
				}
				else
				{
					enuReturnStatLoc = E_NOK_CONFIG_PARM_ERROR ;
				}					
			break ;
			default :
				enuReturnStatLoc =E_NOK_PARAM_OUT_OF_RANGE ;
            break ;				
		}
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
	
}

tenuErrorStatus LED_enuToggle (uint8 u8LedNumCpy )
{
	tenuErrorStatus enuReturnStatLoc = E_OK ; 
	if (u8LedNumCpy < LED_MAX_NUM )
	{
		enuReturnStatLoc = DIO_enuTogglePin(LED_astrLedPinMapping[u8LedNumCpy].u8DioPinMap);
	}
	else
	{
		enuReturnStatLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatLoc ;
}

