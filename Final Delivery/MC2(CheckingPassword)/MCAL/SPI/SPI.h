
#ifndef SPI_H
#define SPI_H
typedef enum {
	WRITE_DONE ,
	WRITE_PENDING,
	WRITE_NOT_DONE , 
    IDLE	
}tenuWriteState;

#define SPI_INT_ENABLE    1
#define SPI_INT_DISABLE   0


void SPI_voidInit(void);

uint8 SPI_u8DataRecieve_Sync(void);
uint8 SPI_u8DataTransfer_Sync(uint8 u8DataCpy);

void SPI_voidWriteData_Async(uint8 u8DataCpy);

tenuWriteState SPI_enuWriteStatus_Async(void);

uint8 SPI_u8ReadData_Async(void);

void SPI_voidSetInterruptState(uint8 u8IntStateCpy);

#endif
