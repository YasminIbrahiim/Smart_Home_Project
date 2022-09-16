#ifndef TWI_H
#define TWI_H


void TWI_voidInit(void);
uint8 TWI_u8ClkFrequencyCalculator(uint8 u8PrescalerCpy , uint8 u8BitRateCpy );
void TWI_enuMasterTransmitSync(uint8 u8SlaveAddressCpy , uint8 u8DataCpy);
void TWI_enuMasterTransmitAsync(uint8 u8SlaveAddressCpy , uint8 u8DataCpy); 
tenuErrorStatus TWI_u8MasterRecieveSync(uint8 u8SlaveAddressCpy , uint8 *pu8ReadDataCpy);
tenuErrorStatus TWI_u8MasterRecieveAsync(uint8 *pu8ReadDataCpy);
void TWI_enuSlaveTransmitSync(uint8 u8DataCpy);
void TWI_enuSlaveTransmitAsync(uint8 u8DataCpy);
tenuErrorStatus TWI_u8SlaveRecieveSync(uint8 *pu8ReadDataCpy);
tenuErrorStatus TWI_u8SlaveRecieveAsync(uint8 *pu8ReadDataCpy);
void TWI_voidInterruptEnable(void);
void TWI_voidInterruptDisable(void);
void TWI_VoidTWIInterruptCallBack(pf pfCallBackcpy);


#endif



