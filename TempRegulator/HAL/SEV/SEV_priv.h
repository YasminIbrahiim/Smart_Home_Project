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
#ifndef SEV_PRIV_H
#define SEV_PRIV_H

#define SEV_u8LED_NUM         ((uint8)7)
#define SEV_u8COMMON_ANODE    ((uint8)0)
#define SEV_u8COMMON_CATHODE  ((uint8)1)
#define SEV_u8WRITE_MAX_NUM   ((uint8) 10)

typedef struct 
{
	uint8 u8SevPins[SEV_u8LED_NUM];
	uint8 u8SevCommonPin  ;
	uint8 u8SevConnection ;
	
}tstrSevPinMappingCfg;

typedef struct {
	uint8 u8Sev_pin_A : 1;
	uint8 u8Sev_pin_B : 1;
	uint8 u8Sev_pin_C : 1;
	uint8 u8Sev_pin_D : 1;
	uint8 u8Sev_pin_E : 1;
	uint8 u8Sev_pin_F : 1;
	uint8 u8Sev_pin_G : 1;
}tstrbfSevPinValueParam;


extern tstrSevPinMappingCfg SEV_astrPinMapping [SEV_MAX_NUM] ;


#endif