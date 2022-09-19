#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "SPI.h"
#include "SPI_cfg.h"
#include "SPI_priv.h"


uint8 SPI_u8RxBuffer  = 0;

uint8 SPI_u8TxState  = 0 ;

void SPI_voidInit(void)
{
	/*
#if SPI_DOR_STATE == SPI_DOR_LSB_FIRST
	SET_BIT(SPCR , 5);
#else
	CLR_BIT(SPCR , 5);	
#endif


#if SPI_CLK_IDLE_STATE  == SPI_CLK_IDLE_HIGH
	SET_BIT(SPCR , 3);
#else
	CLR_BIT(SPCR , 3);
#endif

#if SPI_PHASE_MODE  ==  SPI_PHASE_SETUP_LEADING
	SET_BIT(SPCR , 2);
#else
	CLR_BIT(SPCR , 2);
#endif

#if SPI_GEN_CLK == SPI_FREQ_DIV_2
	CLR_BIT(SPCR, 0 );
	CLR_BIT(SPCR, 1 );
	SET_BIT(SPSR, 0 );

#elif SPI_GEN_CLK == SPI_FREQ_DIV_4
	CLR_BIT(SPCR, 0 );
	CLR_BIT(SPCR, 1 );
	CLR_BIT(SPSR, 0 );

#elif SPI_GEN_CLK == SPI_FREQ_DIV_8
	SET_BIT(SPCR, 0 );
	CLR_BIT(SPCR, 1 );
	SET_BIT(SPSR, 0 );

#elif SPI_GEN_CLK == SPI_FREQ_DIV_16
	SET_BIT(SPCR, 0 );
	CLR_BIT(SPCR, 1 );
	CLR_BIT(SPSR, 0 );

#elif SPI_GEN_CLK == SPI_FREQ_DIV_32
	CLR_BIT(SPCR, 0 );
	SET_BIT(SPCR, 1 );
	SET_BIT(SPSR, 0 );

#elif SPI_GEN_CLK == SPI_FREQ_DIV_64
	CLR_BIT(SPCR, 0 );
	SET_BIT(SPCR, 1 );
	CLR_BIT(SPSR, 0 );

#else
	SET_BIT(SPCR, 0 );
	SET_BIT(SPCR, 1 );
	CLR_BIT(SPSR, 0 );
#endif

#if SPI_MODE == SPI_MASTER_MODE
	SET_BIT(SPCR , 4);
#else
	CLR_BIT(SPCR , 4);
#endif
	CLR_BIT(SPCR , 7);  //disable interrupt
	//Enable SPI
	SET_BIT(SPCR , 6);
	SET_BIT(SPSR , 7); */

#if  SPI_MODE == SPI_MASTER_MODE
	SPCR = (1<<6)|(1<<4)|(1<<0);

#else
	SPCR = (1<<6);

#endif


}

uint8 SPI_u8DataTransfer_Sync(uint8 u8DataCpy)
{

	SPDR  =  u8DataCpy ;

	while (!GET_BIT(SPSR , 7));

	/* write collision check*/
	return SPDR;
}


uint8 SPI_u8DataRecieve_Sync(void)
{
	while(!GET_BIT(SPSR , 7));
	/* write collision check*/
	DIO_enuWritePin(DIO_u8PIN_29,DIO_u8HIGH);
	SPI_u8RxBuffer = SPDR ; 
	return SPI_u8RxBuffer ;
}


void SPI_voidWriteData_Async(uint8 u8DataCpy)
{
	SPDR =  u8DataCpy ;
	SPI_u8TxState = 2;
}

tenuWriteState SPI_enuWriteStatus_Async(void)
{
	tenuWriteState enuReturnStateLoc ;
	if (SPI_u8TxState == 1)
	{
		enuReturnStateLoc = WRITE_DONE ;
		SPI_u8TxState = 0 ;
	}
	else if (SPI_u8TxState == 2 )
	{
		enuReturnStateLoc = WRITE_PENDING ;
	}
	else if (SPI_u8TxState == 3 )
	{
		enuReturnStateLoc = WRITE_NOT_DONE ;
		SPI_u8TxState = 0 ;
	}
	else
	{
		enuReturnStateLoc = IDLE ;
	}

	return enuReturnStateLoc ;
}

uint8 SPI_u8ReadData_Async(void)
{
	return SPI_u8RxBuffer ;
}

void SPI_voidSetInterruptState(uint8 u8IntStateCpy)
{
	if (u8IntStateCpy == SPI_INT_ENABLE )
	{
		SET_BIT (SPCR , 7 ) ;
	}
	else
	{
		CLR_BIT (SPCR , 7 ) ;
	}
}

void __vector_12 (void) __attribute__ ((signal , used)) ;
void __vector_12 (void)
{   
	if ( GET_BIT(SPSR , 6))
	{
		SPI_u8TxState  = 3 ;
	}
	else 
	{
		SPI_u8TxState  = 1 ;
	}
	SPI_u8RxBuffer = SPDR ;
}
