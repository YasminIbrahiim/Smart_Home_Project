#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART.h"
#include "UART_cfg.h"
#include "UART_priv.h"

pf pfTxISR_CallBack;
pf pfRxISR_CallBack;

tenuErrorStatus UART_enuInit(void)
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	/* SET URSEL WHEN WRITING TO UCSRC */
	SET_BIT(UCSRC , 7);
	/* SET CHAR SIZE */
	#if   CHARACTER_SIZE == CHAR_SIZE_5 
	CLR_BIT(UCSRC , 1);
	CLR_BIT(UCSRC , 2);
	CLR_BIT(UCSRB , 2);
	#elif CHARACTER_SIZE == CHAR_SIZE_6 
	SET_BIT(UCSRC , 1);
	CLR_BIT(UCSRC , 2);
	CLR_BIT(UCSRB , 2);
	#elif CHARACTER_SIZE == CHAR_SIZE_7 
	CLR_BIT(UCSRC , 1);
	SET_BIT(UCSRC , 2);
	CLR_BIT(UCSRB , 2);
	#elif CHARACTER_SIZE == CHAR_SIZE_8 
	SET_BIT(UCSRC , 1);
	SET_BIT(UCSRC , 2);
	CLR_BIT(UCSRB , 2);
	#elif CHARACTER_SIZE == CHAR_SIZE_9 
	SET_BIT(UCSRC , 1);
	SET_BIT(UCSRC , 2);
	SET_BIT(UCSRB , 2);
	#else
	tReturnErrorStatusLOC = E_NOK_CONFIG_PARM_ERROR;
	#endif
	
	#if   UART_MODE_SELECT == ASYNC_OPERATION
	CLR_BIT(UCSRC , 6);
	#elif UART_MODE_SELECT == SYNC_OPERATION
	SET_BIT(UCSRC , 6);
	#else
	tReturnErrorStatusLOC = E_NOK_CONFIG_PARM_ERROR;
	#endif
	
	#if   PARITY_MODE == DISABLE_PARITY_MODE
	CLR_BIT(UCSRC, 4);
	CLR_BIT(UCSRC, 5);
	#elif PARITY_MODE == EVEN_PARITY_MODE
	CLR_BIT(UCSRC, 4);
	SET_BIT(UCSRC, 5);
	#elif PARITY_MODE == ODD_PARITY_MODE
	SET_BIT(UCSRC, 4);
	SET_BIT(UCSRC, 5);
	#else
	tReturnErrorStatusLOC = E_NOK_CONFIG_PARM_ERROR;
	#endif
	
	#if   STOP_BIT_SELECT == ONE_STOP_BIT
	CLR_BIT(UCSRC, 3);
	#elif STOP_BIT_SELECT == TWO_STOP_BITS
	SET_BIT(UCSRC, 3);
	#else
	tReturnErrorStatusLOC = E_NOK_CONFIG_PARM_ERROR;	
	#endif
	
	#if   CLOCK_POLARITY == DISABLE_CLK
	CLR_BIT(UCSRC, 0);
	#elif CLOCK_POLARITY == TXD_RISING_RXD_FALLING
	CLR_BIT(UCSRC, 0);
	#elif CLOCK_POLARITY == RXD_RISING_TXD_FALLING 
	SET_BIT(UCSRC, 0);
	#else 
	tReturnErrorStatusLOC = E_NOK_CONFIG_PARM_ERROR;
	#endif
	
	/* CLR URSEL WHEN WRITING TO UBRRH */
	SET_BIT(UBRRH , 7);
	UBRRL  = (uint8)BAUD_RATE_SELECT ;
	UBRRH |= (uint8)(BAUD_RATE_SELECT>>8);

	return tReturnErrorStatusLOC;
	
}
void UART_VoidTxEnable(void)
{
	SET_BIT(UCSRB, 3);
}
void UART_VoidTxDisable(void)
{
	CLR_BIT(UCSRB, 3);
}
void UART_voidRxEnable(void)
{
	SET_BIT(UCSRB, 4);
}
void UART_voidRxDisable(void)
{
	CLR_BIT(UCSRB, 4);
}

tenuErrorStatus UART_enuReadFrameOfData(uint16* pu16ReadDataCpy)
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	if(pu16ReadDataCpy == NULL_PTR)
	{
		tReturnErrorStatusLOC = E_NOK_PARAM_NULL_POINTER;
	}else
	{
		#if   CHARACTER_SIZE == CHAR_SIZE_9
		while(!GET_BIT(UCSRA , 7));
		*pu16ReadDataCpy = (GET_BIT(UCSRB ,1 )<<9) | UDR ;
		#else
		while(!GET_BIT(UCSRA , 7));
		*pu16ReadDataCpy = UDR;
		#endif
		
	}
	return tReturnErrorStatusLOC;
}

void UART_VoidTransmitFrameOfData(uint16 u16TransmitDataCpy)
{
	#if   CHARACTER_SIZE == CHAR_SIZE_9
	while(!GET_BIT(UCSRA , 5));
	UCSRB |=  GET_BIT(u16TransmitDataCpy , 9) ; 
	UDR = (uint8)u16TransmitDataCpy ;

	#else
	while(!GET_BIT(UCSRA , 5));
	UDR = (uint8)u16TransmitDataCpy;
	#endif
	
}
tenuErrorStatus UART_enuReadTrainOfData(uint16* parru16ReadDataCpy, uint8 u8arrSizeCpy )
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	if(parru16ReadDataCpy == NULL_PTR)
	{
		tReturnErrorStatusLOC = E_NOK_PARAM_NULL_POINTER;
	}else
	{
	uint8 u8CountLOC;
	for(u8CountLOC = 0 ; u8CountLOC < u8arrSizeCpy ; u8CountLOC++ )
	{
		#if   CHARACTER_SIZE == CHAR_SIZE_9
		while(!GET_BIT(UCSRA , 7));
		*(parru16ReadDataCpy + u8CountLOC) = (GET_BIT(UCSRB ,1 )<<9) | UDR ;
		#else
		while(!GET_BIT(UCSRA , 7));
		*(parru16ReadDataCpy + u8CountLOC) = UDR;
		#endif
	}
	}
	return tReturnErrorStatusLOC;
}
tenuErrorStatus UART_enuTransmitTrainOfData(uint16* parru16TransmitDataCpy , uint8 u8arrSizeCpy)
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	if(parru16TransmitDataCpy == NULL_PTR)
	{
		tReturnErrorStatusLOC = E_NOK_PARAM_NULL_POINTER;
	}else
	{
	uint8 u8CountLOC;
	for(u8CountLOC = 0 ; u8CountLOC < u8arrSizeCpy ; u8CountLOC++ )
	{
		#if   CHARACTER_SIZE == CHAR_SIZE_9
		while(!GET_BIT(UCSRA , 5));
		UCSRB |=  GET_BIT( *(parru16TransmitDataCpy + u8CountLOC) , 9) ; 
		UDR = (uint8)*(parru16TransmitDataCpy + u8CountLOC) ;
	
		#else
		while(!GET_BIT(UCSRA , 5));
		UDR = (uint8)*(parru16TransmitDataCpy + u8CountLOC);
		#endif
	}
	}
	return tReturnErrorStatusLOC;
}

void UART_VoidRxCompleteInterruptEnable(void)
{
	SET_BIT(UCSRB ,7);
}
void UART_VoidRxCompleteInterruptDisable(void)
{
	CLR_BIT(UCSRB ,7);
}
void UART_VoidTxCompleteInterruptEnable(void)
{
	SET_BIT(UCSRB ,6);
}
void UART_VoidTxCompleteInterruptDisable(void)
{
	CLR_BIT(UCSRB ,6);
}
void UART_VoidRxCompleteInterruptCallBack(pf pfRxCallBackcpy)
{
	pfRxISR_CallBack = pfRxCallBackcpy;
}

void UART_VoidTxCompleteInterruptCallBack(pf pfTxCallBackcpy)
{
	pfTxISR_CallBack = pfTxCallBackcpy;
}



void __vector_13(void) __attribute__((signal, used));
void __vector_13(void)
{
	pfRxISR_CallBack();
}
void __vector_15(void) __attribute__((signal, used));
void __vector_15(void)
{
	pfTxISR_CallBack();
}
