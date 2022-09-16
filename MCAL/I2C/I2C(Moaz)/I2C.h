#ifndef   I2C_H
#define   I2C_H


void I2C_voidInit(void);
void I2C_voidMasterTransmit(uint8 u8SlaveAddressCpy, uint8 * pu8DataCpy, uint8 u8DataSizeCpy);
uint8 I2C_u8SlaveReceive(void);


#endif

