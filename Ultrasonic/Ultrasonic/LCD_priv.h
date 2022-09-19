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


#ifndef LCD_PRIV_H
#define LCD_PRIV_H


#define LCD_u8ONE_LINE  0
#define LCD_u8TWO_LINE  1

#define LCD_u8CHAR_FONT_5X7   0
#define LCD_u8CHAR_FONT_5X11  1


#define LCD_u8DISPLAY_OFF  0
#define LCD_u8DISPLAY_ON   1


#define LCD_u8CURSOR_OFF  0
#define LCD_u8CURSOR_ON   1

#define LCD_u8BLINK_OFF   0
#define LCD_u8BLINK_ON    1


#define LCD_u8MODE_4BIT   0
#define LCD_u8MODE_8BIT   1

#define LCD_u8DECREMENT   0
#define LCD_u8INCREMENT   1


#define LCD_u8SHIFT_OFF   0
#define LCD_u8SHIFT_ON    1


typedef struct {
	uint8 u8PanLine      : 1 ;
	uint8 u8CharFont     : 1 ;
	uint8 u8Display      : 1 ;
	uint8 u8Cursor       : 1 ;
	uint8 u8Blink        : 1 ;
	uint8 u8Mode         : 1 ;
	uint8 u8Increment    : 1 ;
	uint8 u8DisplayShift : 1 ;
}tstrLcdOpCfg;

typedef struct 
{
	
	uint8      u8RegisterSelect ;
	uint8      u8ReadWrite      ;
	uint8      u8EnableLatch    ;
	uint8      u8DataPinMapping [8] ;
	
	
}tstrLcdPinCfg;

typedef struct 
{
	tstrLcdOpCfg     strLcdOpcfg ;
	tstrLcdPinCfg    strLcdPinCfg ;
}tstrLcdCfg;

tstrLcdCfg LCD_astrCfg [LCD_MAX_NUM] ;

#endif
