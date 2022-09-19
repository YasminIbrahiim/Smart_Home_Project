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
#ifndef DC_Motor_CFG_H
#define DC_Motor_CFG_H

#define DC_Motor_forward  	       ((uint8) 0xAA)
#define DC_Motor_backward  	       ((uint8) 0x55)
#define DC_Motor_off     	       ((uint8) 0x66)


#define DC_Motor_u8NUM_0     ((uint8 ) 0)
#define DC_Motor_u8NUM_1     ((uint8 ) 1)
#define DC_Motor_u8NUM_2     ((uint8 ) 2)
#define DC_Motor_u8NUM_3     ((uint8 ) 3)
#define DC_Motor_u8NUM_4     ((uint8 ) 4)

#define DC_Motor_MAX_NUM     ((uint8) 2)


#endif

