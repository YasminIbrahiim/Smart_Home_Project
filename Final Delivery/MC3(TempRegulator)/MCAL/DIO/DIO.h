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
/** aaboelno     Ahmed Abo Elnour          ITI.                                 */
/**-----------------------------------------------------------------------------*/
/**               R E V I S I O N   H I S T O R Y                               */
/**-----------------------------------------------------------------------------*/
/** Date        Version   Author       Description                              */
/** ----------  --------  ------      ------------------------------------------*/
/** 21/08/2022   0.1       aaboelno     Initial Creation                        */
/********************************************************************************/

#ifndef   DIO_H
#define   DIO_H

typedef struct {
	
	uint8 u8PinNum   ;
	uint8 u8PinValue ;
	tenuErrorStatus enuStatus;
	
}tstrPinMapping ;


#define DIO_u8OUTPUT           ((uint8)0x01)     
#define DIO_u8INPUT            ((uint8)0x00)

/*-------------------------------------------------*/
#define DIO_u8HIGH              ((uint8)0x01)     
#define DIO_u8LOW               ((uint8)0x00)
/*-------------------------------------------------*/
#define DIO_u8ACTIVATE       ((uint8)0x01)     
#define DIO_u8DEACTIVATE     ((uint8)0x00)

/*-------------------------------------------------*/
#define DIO_u8PIN_0     ((uint8 )0)
#define DIO_u8PIN_1     ((uint8 )1)
#define DIO_u8PIN_2     ((uint8 )2)
#define DIO_u8PIN_3     ((uint8 )3)
#define DIO_u8PIN_4     ((uint8 )4)
#define DIO_u8PIN_5     ((uint8 )5)
#define DIO_u8PIN_6     ((uint8 )6)
#define DIO_u8PIN_7     ((uint8 )7)

/*-------------------------------------------------*/
#define DIO_u8PIN_8     ((uint8 ) 8 )
#define DIO_u8PIN_9     ((uint8 ) 9 )
#define DIO_u8PIN_10    ((uint8 ) 10)
#define DIO_u8PIN_11    ((uint8 ) 11)
#define DIO_u8PIN_12    ((uint8 ) 12)
#define DIO_u8PIN_13    ((uint8 ) 13)
#define DIO_u8PIN_14    ((uint8 ) 14)
#define DIO_u8PIN_15    ((uint8 ) 15)
						
/*-------------------------------------------------*/
#define DIO_u8PIN_16     ((uint8 ) 16)
#define DIO_u8PIN_17     ((uint8 ) 17)
#define DIO_u8PIN_18     ((uint8 ) 18)
#define DIO_u8PIN_19     ((uint8 ) 19)
#define DIO_u8PIN_20     ((uint8 ) 20)
#define DIO_u8PIN_21     ((uint8 ) 21)
#define DIO_u8PIN_22     ((uint8 ) 22)
#define DIO_u8PIN_23     ((uint8 ) 23)

/*-------------------------------------------------*/
#define DIO_u8PIN_24     ((uint8 ) 24)  
#define DIO_u8PIN_25     ((uint8 ) 25)  
#define DIO_u8PIN_26     ((uint8 ) 26)  
#define DIO_u8PIN_27     ((uint8 ) 27)  
#define DIO_u8PIN_28     ((uint8 ) 28)  
#define DIO_u8PIN_29     ((uint8 ) 29)  
#define DIO_u8PIN_30     ((uint8 ) 30)  
#define DIO_u8PIN_31     ((uint8 ) 31)  

/*-------------------------------------------------*/

/********************************************************************************/
/** Description : Scan cfg file and Apply on pins registers the configurations  */
/********************************************************************************/

void DIO_voidInit(void);

/* Description : function write DIO_u8HIGH or DIO_u8LOW on Pin start 0 to 31 */
tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy , uint8 u8PinValueCpy);


tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy , uint8 * pu8PinValueCpy);

tenuErrorStatus DIO_enuPullWrite(uint8 u8PinNumCpy , uint8 u8PinStateCpy);

tenuErrorStatus DIO_enuWriteBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy );

tenuErrorStatus DIO_enuReadBus(tstrPinMapping * pastrPinMappingCpy , uint8 u8SizeCpy );

tenuErrorStatus DIO_enuWritePinDir(uint8 u8PinNumCpy , uint8 u8PinDirCpy);

tenuErrorStatus DIO_enuTogglePin(uint8 u8PinNumCpy);

#endif

