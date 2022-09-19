#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"

#include "UART.h"
#include "UART_cfg.h"
#include "UART_priv.h"


void UART_voidInit(void)
{
	 	 /*Set URSEL to access UCSRC Reg*/
	 	 SET_BIT(UCSRC,7);

	 	 /*Receive enable config*/
#if UART_RIECEVE_ENABLE == UART_ENABLED
		 SET_BIT(UCSRB,4);
#elif
		 CLR_BIT(UCSRB,4);
#endif


		 /*Send enable config*/
#if UART_SEND_ENABLE == UART_ENABLED
		 SET_BIT(UCSRB,3);
#elif
		 CLR_BIT(UCSRB,3);
#endif

		 /*Receive interrupt enable config*/
#if UART_RX_INTERRUPT_ENABLE == UART_DISABLED
		 SET_BIT(UCSRB,7);
#elif
		 CLR_BIT(UCSRB,7);
#endif

		 /*Send interrupt enable config*/
#if UART_TX_INTERRUPT_ENABLE == UART_DISABLED
		 SET_BIT(UCSRB,6);
#elif
		 CLR_BIT(UCSRB,6);
#endif

		 /*UDR empty interrupt enable config*/

#if UART_UDR_INTERRUPT_ENABLE == UART_DISABLED
		 SET_BIT(UCSRB,5);
#elif
		 CLR_BIT(UCSRB,5);
#endif


		 SET_BIT(UCSRB,5);

		 /*Mode config (Asynchronous-Synchronous)*/
#if UART_MODE_SELECT == UART_ASYNCHRONOUS
		 SET_BIT(UCSRC,6);
#elif
		 CLR_BIT(UCSRC,6);
#endif

		 /*Parity Mode config*/
		 UCSRC|=(UART_PARITY_MODE<<4);
#if UART_CLOCK_POLARITY == UART_SAMPLE_FALLING_EDGE
		 SET_BIT(UCSRC,0);
#elif
		 CLR_BIT(UCSRC,0);
#endif

		 /*Stop Bits config*/
#if UART_STOP_BIT_NO == UART_1_STOP_BIT
		 SET_BIT(UCSRC,3);
#elif
		 CLR_BIT(UCSRC,3);
#endif


		 /*Character size config*/
#if UART_CHAR_SIZE == UART_5_BITS
		 CLR_BIT(UCSRC,1);
		 CLR_BIT(UCSRC,2);
		 CLR_BIT(UCSRB,2);
#elif UART_CHAR_SIZE == UART_6_BITS
		 SET_BIT(UCSRC,1);
		 CLR_BIT(UCSRC,2);
		 CLR_BIT(UCSRB,2);
#elif UART_CHAR_SIZE == UART_7_BITS
		 CLR_BIT(UCSRC,1);
		 SET_BIT(UCSRC,2);
		 CLR_BIT(UCSRB,2);
#elif UART_CHAR_SIZE == UART_8_BITS
		 SET_BIT(UCSRC,1);
		 SET_BIT(UCSRC,2);
		 CLR_BIT(UCSRB,2);
#else
		 SET_BIT(UCSRC,1);
		 SET_BIT(UCSRC,2);
		 SET_BIT(UCSRB,2);
#endif


		 /*Baud Rate Value Config*/
		 UBRRH = 0;
		 UBRRL = UART_BAUD_RATE;

}

void UART_voidSendByte(uint8 Copy_u8Byte)
{
	/*wait while previous sending is complete*/
	while((GET_BIT(UCSRA,5))==0 );
	/*send byte*/
	UDR = Copy_u8Byte;
}

uint8 UART_voidRecieveByte(uint16 Copy_u16Timeout)
{
	/*wait for incoming byte for Timeout period*/
	do
	{
		/*if a byte received return received byte*/
		if ( (GET_BIT(UCSRA,7)) == 1)
		{
			return UDR;

		}

	}while(--Copy_u16Timeout);

	 /*if no data received return 0*/
	return 0;
}
