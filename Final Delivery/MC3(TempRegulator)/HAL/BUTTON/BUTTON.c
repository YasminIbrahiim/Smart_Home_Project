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
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "BUTTON.h"

#include "BUTTON_cfg.h"
#include "BUTTON_priv.h"

void button_voidInit(void)
{
	uint8 u8CntrLoc ;
	for (u8CntrLoc = 0 ; u8CntrLoc < BUTTON_MAX_NUM ; u8CntrLoc++)
	{
		if(Button_astrButtonPinMapping[u8CntrLoc].u8DioPinsMap >= DIO_u8PIN_0 &&
		   Button_astrButtonPinMapping[u8CntrLoc].u8DioPinsMap <= DIO_u8PIN_31	)
		{
			if(Button_astrButtonPinMapping[u8CntrLoc].u8ButtonModeConc == BUTTON_u8PullUp)
			{

				Button_astrButtonPinMapping[u8CntrLoc].tenuBtn_ErrorState = DIO_enuPullWrite(Button_astrButtonPinMapping[u8CntrLoc].u8DioPinsMap , DIO_u8HIGH);

			}
			else if(Button_astrButtonPinMapping[u8CntrLoc].u8ButtonModeConc == BUTTON_u8PullDown)
			{
				Button_astrButtonPinMapping[u8CntrLoc].tenuBtn_ErrorState = DIO_enuPullWrite(Button_astrButtonPinMapping[u8CntrLoc].u8DioPinsMap , DIO_u8LOW);
			}
			else{
				Button_astrButtonPinMapping[u8CntrLoc].tenuBtn_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			}

		}
		else
		{
			Button_astrButtonPinMapping[u8CntrLoc].tenuBtn_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
		}

	}

}


tenuErrorStatus Button_enuPressedValue(uint8 u8ButtonNumCpy , uint8 * u8ButtonValueCpy)
{
	tenuErrorStatus BTN_ErrorState = E_OK;
	if(u8ButtonValueCpy != NULL_PTR)
	{

		if(Button_astrButtonPinMapping[u8ButtonNumCpy].u8DioPinsMap >= DIO_u8PIN_0 &&
		   Button_astrButtonPinMapping[u8ButtonNumCpy].u8DioPinsMap <= DIO_u8PIN_31	)
		{

			BTN_ErrorState = DIO_enuReadPin(Button_astrButtonPinMapping[u8ButtonNumCpy].u8DioPinsMap , u8ButtonValueCpy);

			switch(Button_astrButtonPinMapping[u8ButtonNumCpy].u8ButtonModeConc)
			{

			case BUTTON_u8PullUp:
				*u8ButtonValueCpy = !(*u8ButtonValueCpy);
			break;

			case BUTTON_u8PullDown:
				//keep the same value
			break;

			default:
				BTN_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			break;
			}

		}
		else
		{
			BTN_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
		}

	}
	else
	{
		BTN_ErrorState = E_NOK_PARAM_NULL_POINTER;
	}


	return BTN_ErrorState;
}
