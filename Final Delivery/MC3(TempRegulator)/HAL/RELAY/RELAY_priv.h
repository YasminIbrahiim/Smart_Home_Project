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
#ifndef RELAY_PRIV_H
#define RELAY_PRIV_H


#define Relay_u8extHIGH	        ((uint8) 0xCA)
#define Relay_u8extLOW          ((uint8) 0xC5)

#define Relay_extSupply	   		1
#define Relay_intSupply	   		2

#define Relay_ACNC   			((uint8) 0xFF)
#define Relay_ACNO	   			((uint8) 0x15)


typedef struct
{
	uint8 u8SupplyType;
	uint8 u8PinMap;
}tstrRelayModeextConc;

typedef struct
{
	uint8 u8Pin1Map;
	uint8 u8Pin2Map;
}tstrRelayModeintConc;

typedef union
{
	tstrRelayModeextConc u8extSupply;
	tstrRelayModeintConc u8inpSupply;

}tuninRelayPin;



typedef struct
{
	uint8 u8PinNumbers;
	uint8 u8ACMode;
	tuninRelayPin u8DioPinCfg;
	tenuErrorStatus tenuRelay_ErrorState;
}tstrRelayCfg;

extern tstrRelayCfg Relay_astrPinMapping[RELAY_MAX_NUM];

#endif
