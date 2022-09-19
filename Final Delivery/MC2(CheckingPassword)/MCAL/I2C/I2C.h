#ifndef   I2C_H
#define   I2C_H
#include "I2C_priv.h"


void I2C_voidInit(void);
void TWI_voidStart(void);
void TWI_voidStop(void);
void TWI_voidWrite(uint8 u8DataCpy);
uint8 TWI_u8Read_ACK(void);
uint8 TWI_u8Read_NACK(void);
uint8 TWI_u8Get_Status(void);
void I2C_voidMasterTransmit(uint8 u8SlaveAddressCpy, uint8 * pu8DataCpy, uint8 u8DataSizeCpy);
void I2C_voidSlaveReceive(uint8 *pu8DataCpy, uint8 u8ArraySizeCpy);
#endif

