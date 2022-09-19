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
/** nshfik     nourhan shafik          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 30/08/2022   0.1       nshfik     Initial Creation                        */
/********************************************************************************/
#ifndef DC_Motor_PRIV_H
#define DC_Motor_PRIV_H

#define DC_Motor_u8POS	           ((uint8) 0x00)
#define DC_Motor_u8NEG             ((uint8) 0xFF)

#define DC_Motor_u8extHIGH	       ((uint8) 0xCA)
#define DC_Motor_u8extLOW          ((uint8) 0xC5)

#define DC_Motor_extSupply	   		1
#define DC_Motor_intSupply	   		2


typedef struct
{
	uint8 u8SupplyType;
	uint8 u8PinConnect;
	uint8 u8PinMap;
}tstrDCMotorModeextConc;

typedef struct
{
	uint8 u8Pin1Connect;
	uint8 u8Pin2Connect;
	uint8 u8Pin1Map;
	uint8 u8Pin2Map;
}tstrDCMotorModeintConc;

typedef union
{

	tstrDCMotorModeextConc u8extSupply;
	tstrDCMotorModeintConc u8inpSupply;

}tuninDCMotorPin;




typedef struct
{
	uint8 u8PinNumbers;
	tuninDCMotorPin u8DioPinCfg;
	tenuErrorStatus tenuDCMotor_ErrorState;
}tstrDCMotorCfg;

extern tstrDCMotorCfg DC_Motor_astrPinMapping[DC_Motor_MAX_NUM];

#endif
