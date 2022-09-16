#include "STD_Types.h"
#include "BIT_Math.h"

#include "UART.h"
#include "UART_cfg.h"
#include "UART_priv.h"

pf pfTxISR_CallBack;
pf pfRxISR_CallBack;

void UART_voidInit(void)
{
	SET_BIT(UCSRB, 3);  	/* Enable transmitting and recieving data */
	SET_BIT(UCSRB, 4);
	
	#if   UART_MODE == UART_SYNC_MODE
		SET_BIT(UCSRC , 6);
	#if   UART_CLK_POLARITY == RISING_TX_FALLING_RX
		CLR_BIT(UCSRC , 0);
	#else
		SET_BIT(UCSRC , 0);
	#endif
	#else                                  /*Asyc Mode*/
		CLR_BIT(UCSRC , 6);
	#endif
	
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
	#else                            /* set character sizee 8 as default */
	SET_BIT(UCSRC , 1);
	SET_BIT(UCSRC , 2);
	CLR_BIT(UCSRB , 2);
	#endif
	
	#if   UART_MODE == UART_ASYNC_MODE
		
		/* Select Parity Mode */
	#if   UART_PARITY_MODE == UART_EVEN_PARITY_MODE
		CLR_BIT(UCSRC , 4);
		SET_BIT(UCSRC , 5);
	#elif  UART_PARITY_MODE == UART_ODD_PARITY_MODE	
		SET_BIT(UCSRC , 4);
		SET_BIT(UCSRC , 5);
	#elif  UART_PARITY_MODE == UART_RESERVED_PARITY_MODE 
		SET_BIT(UCSRC , 4);
		CLR_BIT(UCSRC , 5);
	#else                              /*Parity feature is disabled*/
		CLR_BIT(UCSRC , 4);
		CLR_BIT(UCSRC , 5);
	#endif 
	
	   /* STOP BITS */
	#if   UART_STOP_BITS_NUMBER == UART_ONE_STOP_BIT
		CLR_BIT(UCSRC , 3);
	#elif UART_STOP_BITS_NUMBER == UART_TWO_STOP_BIT
		SET_BIT(UCSRC , 3);
	#else
		SET_BIT(UCSRC , 3);           /* Set 2 stop bits as default */
	#endif
	
	  /* Baud Rate */
	SET_BIT(UBRRH , 7);
	UBRRL  = (uint8)BAUD_RATE_SELECT ;
	UBRRH |= (uint8)(BAUD_RATE_SELECT>>8);
	
	#endif
	
}

void UART_voidTransmitSync(uint8 u8DataCpy)
{
	#if   CHARACTER_SIZE == CHAR_SIZE_9
	while(!GET_BIT(UCSRA , 5));
	UCSRB |=  GET_BIT(u8DataCpy , 9) ; 
	UDR = u8DataCpy ;

	#else
	while(!GET_BIT(UCSRA , 5));
	UDR = (uint8)u8DataCpy;
	#endif
}
void UART_voidTransmitAsync(uint8 u8DataCpy)
{
	
}
uint8 UART_voidRecieveSync(void)
{
	#if   CHARACTER_SIZE == CHAR_SIZE_9
	while(!GET_BIT(UCSRA , 7));
	return (GET_BIT(UCSRB ,1 )<<9) | UDR ;
	#else
	while(!GET_BIT(UCSRA , 7));
	return UDR;
	#endif

}
uint8 UART_voidRecieveAsync(void)
{

}

void UART_TxInterruptEnable(void)
{
	SET_BIT(UCSRC , 6);
}
void UART_TxInterruptDisable(void)
{
	CLR_BIT(UCSRC , 6);
}
void UART_RxInterruptEnable(void)
{
	SET_BIT(UCSRC , 7);
}
void UART_RxInterruptDisable(void)
{
	CLR_BIT(UCSRC , 7);
}
void UART_voidTxInterruptCallBack(pf pfTxCallBackCpy)
{
	pfTxISR_CallBack = pfTxCallBackCpy;
}
void UART_voidRxInterruptCallBack(pf pfRxCallBackCpy)
{
	pfRxISR_CallBack = pfRxCallBackCpy;
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

