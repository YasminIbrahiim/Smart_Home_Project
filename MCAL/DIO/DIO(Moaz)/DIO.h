/********************************************************************************/
/**    File Name: DIO.h                                                         */
/**                                                                             */
/**  Description: Implementation of the DIO contain interfaces for the module   */
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
/** mahmed       Moaz Ahmed Mohamed         ITI.                                */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1      mahmed       Initial Creation                         */
/********************************************************************************/
#ifndef DIO_H
#define DIO_H

typedef struct 
{
	uint8 u8PinNum  ;
	uint8 u8PinValue;
	tenuErrorStatus enuStatus;
}tstrPinMapping ;


#define DIO_u8HIGH              ((uint8)0x01)
#define DIO_u8LOW               ((uint8)0x00)
/*---------------------------------------------*/
#define DIO_u8ACTIVATE          ((uint8)0x01)
#define DIO_u8DEACTIVATE        ((uint8)0x00)
/*---------------------------------------------*/
#define DIO_u8OUTPUT            ((uint8)0x01)
#define DIO_u8INPUT             ((uint8)0x00)
/*---------------------------------------------*/
#define DIO_u8_PIN_0        ((uint8)0)  
#define DIO_u8_PIN_1        ((uint8)1)
#define DIO_u8_PIN_2        ((uint8)2)
#define DIO_u8_PIN_3        ((uint8)3)
#define DIO_u8_PIN_4        ((uint8)4)
#define DIO_u8_PIN_5        ((uint8)5)
#define DIO_u8_PIN_6        ((uint8)6)
#define DIO_u8_PIN_7        ((uint8)7)
/*---------------------------------------------*/                           
#define DIO_u8_PIN_8        ((uint8)8)
#define DIO_u8_PIN_9        ((uint8)9)
#define DIO_u8_PIN_10       ((uint8)10)
#define DIO_u8_PIN_11       ((uint8)11)
#define DIO_u8_PIN_12       ((uint8)12)
#define DIO_u8_PIN_13       ((uint8)13)
#define DIO_u8_PIN_14       ((uint8)14)
#define DIO_u8_PIN_15       ((uint8)15)
/*---------------------------------------------*/                            
#define DIO_u8_PIN_16       ((uint8)16)
#define DIO_u8_PIN_17       ((uint8)17)
#define DIO_u8_PIN_18       ((uint8)18)
#define DIO_u8_PIN_19       ((uint8)19)
#define DIO_u8_PIN_20       ((uint8)20)
#define DIO_u8_PIN_21       ((uint8)21)
#define DIO_u8_PIN_22       ((uint8)22)
#define DIO_u8_PIN_23       ((uint8)23)
/*---------------------------------------------*/                            
#define DIO_u8_PIN_24       ((uint8)24)
#define DIO_u8_PIN_25       ((uint8)25)
#define DIO_u8_PIN_26       ((uint8)26)
#define DIO_u8_PIN_27       ((uint8)27)
#define DIO_u8_PIN_28       ((uint8)28)
#define DIO_u8_PIN_29       ((uint8)29)
#define DIO_u8_PIN_30       ((uint8)30)
#define DIO_u8_PIN_31       ((uint8)31)
/*---------------------------------------------*/


/* Description: Scan cfg file and Apply on pins registers the configurations*/
void DIO_voidInit(void);
/* Description: function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31*/
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCPy);
/* Description: function to read the value on the pins (0 or 1) starting from pin 0 to pin 31*/
tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy, uint8 * pu8PinValueCpy);
/* Description: function to activate the pull up register on a specific pin*/
tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy);
/* Description: function to write on several pins in the same time*/
tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy);
/* Description: function to read the values on several pins*/
tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy);
/* Description: function to set the direction of specofic pin DIO_u8OUTPUT or DIO_u8INPUT*/
tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy);
/* Description: function to set change the state of specific pin from high to low and vice versa*/
tenuErrorStatus DIO_enuTogglePin(uint8 u8LedMappingCpy);

/* Description: function to read the value on the DDR (0 or 1) starting from pin 0 to pin 31*/
tenuErrorStatus DIO_enuReadPinDir(uint8 u8PinNumCpy, uint8 * pu8PinValueCpy);

#endif  