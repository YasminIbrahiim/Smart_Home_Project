/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain Private file for the module */
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
/** 21/08/2022   0.1       aaboelno     Initial Creation                        */
/********************************************************************************/

#ifndef   DIO_PRIV_H
#define   DIO_PRIV_H


#define DIO_OUTPUT           1     
#define DIO_INPUT            0

#define  DIO_u8PIN_SIZE               ((uint8 )8)
#define  DIO_u8MAX_NUMBER_OF_PINS     ((uint8 ) 32) 

#define ODRA  *((volatile uint8 *)0x3B)
#define ODRB  *((volatile uint8 *)0x38)
#define ODRC  *((volatile uint8 *)0x35)
#define ODRD  *((volatile uint8 *)0x32)

#define DDRA  *((volatile uint8 *)0x3A)
#define DDRB  *((volatile uint8 *)0x37)
#define DDRC  *((volatile uint8 *)0x34)
#define DDRD  *((volatile uint8 *)0x31)

#define IDRA  *((volatile uint8 *)0x39)
#define IDRB  *((volatile uint8 *)0x36)
#define IDRC  *((volatile uint8 *)0x33)
#define IDRD  *((volatile uint8 *)0x30)

#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)          CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_MARCO(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0


/** Secure Configuration file */
#ifndef DIO_u8DIR_PIN_0
#define DIO_u8DIR_PIN_0 DIO_INPUT 
#endif 
 

#endif



