/********************************************************************************/
/**    File Name: LCD.h                                                         */
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

#include "LCD_cfg.h"
#include "LCD_priv.h"

tstrLcdCfg LCD_astrCfg [LCD_MAX_NUM]={
	/* LCD 1 Configuration */
	{
		/* LCD operation Configuration */
		{
			LCD_u8TWO_LINE   , LCD_u8CHAR_FONT_5X11 ,
            LCD_u8DISPLAY_ON , LCD_u8CURSOR_OFF    ,	
			LCD_u8BLINK_OFF  , LCD_u8MODE_8BIT     ,
			LCD_u8INCREMENT  , LCD_u8SHIFT_OFF
		}
		,
		/* LCD DIO PIN Mapping Configuration */
		{
			/* RS          RW          EN     */
			 DIO_u8PIN_0,DIO_u8PIN_1 ,DIO_u8PIN_2,
			/* Data0       Data1       Data2  */
			{DIO_u8PIN_3,DIO_u8PIN_4 ,DIO_u8PIN_5,
			
			/* Data3       Data4       Data5  */
			 DIO_u8PIN_6,DIO_u8PIN_7,DIO_u8PIN_8,
			 
			/* Data6         Data7  */
			 DIO_u8PIN_9, DIO_u8PIN_10}
			
		}
	}

	
};


