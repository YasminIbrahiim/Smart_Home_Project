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
#ifndef SEV_H
#define SEV_H

#include "SEV_cfg.h"

#define SEV_u8ON        ((uint8) 1)
#define SEV_u8OFF       ((uint8) 0)

#define SEV_u8WRITE_NUM_0     ((uint8) 0)
#define SEV_u8WRITE_NUM_1     ((uint8) 1)
#define SEV_u8WRITE_NUM_2     ((uint8) 2)
#define SEV_u8WRITE_NUM_3     ((uint8) 3)
#define SEV_u8WRITE_NUM_4     ((uint8) 4)
#define SEV_u8WRITE_NUM_5     ((uint8) 5)
#define SEV_u8WRITE_NUM_6     ((uint8) 6)
#define SEV_u8WRITE_NUM_7     ((uint8) 7)
#define SEV_u8WRITE_NUM_8     ((uint8) 8)
#define SEV_u8WRITE_NUM_9     ((uint8) 9)

tenuErrorStatus SEV_enuWrite(uint8 u8SevNumCpy , uint8 u8ValueCpy);
tenuErrorStatus SEV_enuWrite2Digits(uint8 u8SevNumCpy1 ,uint8 u8SevNumCpy0, uint8 u8ValueCpy);
tenuErrorStatus SEV_enuMode(uint8 u8SevNumCpy  , uint8 u8ModeCpy);

#endif




