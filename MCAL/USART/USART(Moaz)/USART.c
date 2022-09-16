#include "Std_types.h"
#include "bitManipulation.h"


#include "USART.h"
#include "USART_cfg.h"
#include "USART_priv.h"

void USART_voidTransmitPolling(uint16 DataCpy);
void USART_voidHelpUBRR(uint8 u8BoolDoubleSpeed , uint8 u8BaudRate);
void USART_voidTransmitInterrupt(void);
uint16 USART_u16ReceivePolling(void);

uint16 TransmittedData;
uint16 ReceivedData ;
void USART_voidInit(void)
{
	CLR_BIT(UCSRA,0); // Disable MultiProcessor Mode
	CLR_BIT(UCSRA,7); // Initilize that receive buffer is empty
	CLR_BIT(UCSRA,4); // Clearing Frame Error Flag
	CLR_BIT(UCSRA,3); // Clearing Data OverRun Flag
	CLR_BIT(UCSRA,2); // Clearing Parity Error Flag
	switch(RTX_MODE)
	{
	case TRANSMIT_ONLY:
		SET_BIT(UCSRB,3);
		CLR_BIT(UCSRB,4);
		break;
	case RECEIVE_ONLY:
		CLR_BIT(UCSRB,3);
		SET_BIT(UCSRB,4);
		break;
	case TRANSMIT_RECEIVE:
		SET_BIT(UCSRB,3);
		SET_BIT(UCSRB,4);
		break;
	}
	switch(ACK_MODE)
	{
	case POLLING_BASED:
		UCSRB &= (ACK_MODE);
		break;
	case INTERRUPT_BASED:
		UCSRB &= (ACK_MODE);
		break;
	}
	SET_BIT(UCSRC,7); // To Write in UCSRC Register Not UBBRH
	switch(PARITY_MODE)
	{
	case PARITY_DISABLED:
		CLR_BIT(UCSRC,4);
		CLR_BIT(UCSRC,5);
		break;
	case PARITY_EVEN:
		CLR_BIT(UCSRC,4);
		SET_BIT(UCSRC,5);
		break;
	case PARITY_ODD:
		SET_BIT(UCSRC,4);
		SET_BIT(UCSRC,5);
		break;
	}
	switch(STOPPING_BITS)
	{
	case ONE_STOPPING_BIT:
		CLR_BIT(UCSRC,3);
		break;
	case TWO_STOPPING_BITS:
		SET_BIT(UCSRC,3);
		break;
	}
	switch(CHAR_SIZE)
	{
	case CHAR_SIZE_5_BITS:
		CLR_BIT(UCSRC,1);
		CLR_BIT(UCSRC,2);
		CLR_BIT(UCSRB,2);
		break;
	case CHAR_SIZE_6_BITS:
		SET_BIT(UCSRC,1);
		CLR_BIT(UCSRC,2);
		CLR_BIT(UCSRB,2);
		break;
	case CHAR_SIZE_7_BITS:
		CLR_BIT(UCSRC,1);
		SET_BIT(UCSRC,2);
		CLR_BIT(UCSRB,2);
		break;
	case CHAR_SIZE_8_BITS:
		SET_BIT(UCSRC,1);
		SET_BIT(UCSRC,2);
		CLR_BIT(UCSRB,2);
		break;
	case CHAR_SIZE_9_BITS:
		SET_BIT(UCSRC,1);
		SET_BIT(UCSRC,2);
		SET_BIT(UCSRB,2);
		break;
	}
	switch(USART_MODE)
	{
	case UART_MODE:
		CLR_BIT(UCSRC,6); // Making It Async
		CLR_BIT(UCSRC,0); // Disabling Clock Polarity
		if(DOUBLE_SPEED == DOUBLE_SPEED_ENABLE)
		{
			SET_BIT(UCSRA,1); // Enabling Double Speed Mode
			USART_voidHelpUBRR(DOUBLE_SPEED_ENABLE,BAUD_RATE);
		}
		else if(DOUBLE_SPEED == DOUBLE_SPEED_DISABLE)
		{
			CLR_BIT(UCSRA,1); // Disabling Double Speed Mode
			USART_voidHelpUBRR(DOUBLE_SPEED_DISABLE,BAUD_RATE);
		}
		else
		{
		}

		break;

	case USRT_MODE:
		SET_BIT(UCSRC,6); // Making It Sync
		CLR_BIT(UCSRA,1); // Disabling Double Speed Mode
		if(RTX_CLK == SYNC_TRising_RFalling)
		{
			CLR_BIT(UCSRC,0); // Transmit on Rising && Receive on Falling
		}
		else if (RTX_CLK == SYNC_TFalling_TRising)
		{
			SET_BIT(UCSRC,0); // Transmit on Falling && Receive on Rising
		}
		else
		{
		}
		break;
	}
}
void USART_voidTransmit(uint16 DataCpy)
{
	DataCpy &= (0x1FF); // Setting bits 10-15 to Zero
	switch(ACK_MODE)
	{
	case INTERRUPT_BASED:
		TransmittedData = DataCpy;
		USART_voidTransmitInterrupt();
		break;

	case POLLING_BASED:
		USART_voidTransmitPolling(DataCpy);
		break;
	}
}
uint16 USART_u16Receive(void)
{
	uint16 ReceivedDataLoc;
	switch(ACK_MODE)
	{
	case INTERRUPT_BASED:
		return 0;
		break;

	case POLLING_BASED:
		ReceivedDataLoc = USART_u16ReceivePolling();
		return ReceivedDataLoc;
		break;
	}
}


 void USART_voidHelpUBRR(uint8 u8BoolDoubleSpeed , uint8 u8BaudRate)
{
	 CLR_BIT(UBBRH,7); // To Write To UBBRH Not UCSRC Register
	 uint32 u32UBRR = 0;
	switch(u8BoolDoubleSpeed)
	{
	case DOUBLE_SPEED_ENABLE:
		u32UBRR = FOSC / 8;
		switch(u8BaudRate)
		{
		case BAUD_RATE_2400:
			u32UBRR = (u32UBRR / 2400)-1;
			break;
		case BAUD_RATE_4800:
			u32UBRR = (u32UBRR / 4800)-1;
			break;
		case BAUD_RATE_9600:
			u32UBRR = (u32UBRR / 9600)-1;
			break;
		}
		break;
	case DOUBLE_SPEED_DISABLE:
		u32UBRR = FOSC / 16;
		switch(u8BaudRate)
		{
		case BAUD_RATE_2400:
			u32UBRR = (u32UBRR / 2400)-1;
			break;
		case BAUD_RATE_4800:
			u32UBRR = (u32UBRR / 4800)-1;
			break;
		case BAUD_RATE_9600:
			u32UBRR = (u32UBRR / 9600)-1;
			break;
		}
		break;
	}
	UBBRH |= (u32UBRR >> 8);
	UBBRL = (uint8)u32UBRR;
}
void USART_voidTransmitInterrupt(void)
{
	switch(CHAR_SIZE)
	{
	case CHAR_SIZE_9_BITS:
		UCSRB |= (TransmittedData>>8);
		UDR = (uint8)TransmittedData;
		break;

	default :
		UDR = (uint8)TransmittedData;
		break;
	}
}
void USART_voidTransmitPolling(uint16 DataCpy)
{
	while(GET_BIT(UCSRA,5) != 1);
	switch(CHAR_SIZE)
	{
	case CHAR_SIZE_9_BITS:
		UCSRB |= (DataCpy>>8);
		UDR = (uint8)DataCpy;
		break;

	default :
		UDR = (uint8)DataCpy;
		break;
	}

}

uint16 USART_u16ReceivePolling(void)
{
	uint16 u16ReturnLoc =0;
	while(GET_BIT(UCSRA,7) != 1); // Polling until there is unread data in Buffer
	switch(PARITY_MODE)
	{
	case PARITY_DISABLED:
		if(GET_BIT(UCSRA,4) || GET_BIT(UCSRA,3)) // Checking Frame Error, Dataoverrun only , parity is disabled
		{
			return 0; // Buffer Contains Garbage
		}
		else
		{
			switch(CHAR_SIZE)
			{
			case CHAR_SIZE_9_BITS:
				u16ReturnLoc = ((UCSRB & 0x002) << 7);
				u16ReturnLoc |= UDR;
				return u16ReturnLoc;
				break;

			default :
				return UDR;
				break;
			}
		}
		break;
	default :
		if(GET_BIT(UCSRA,4) || GET_BIT(UCSRA,3) || GET_BIT(UCSRA,2)) // Checking Frame Error, Data overrun and parity
		{
			return 0; // Buffer Contains Garbage
		}
		else
		{
			switch(CHAR_SIZE)
			{
			case CHAR_SIZE_9_BITS:
				u16ReturnLoc = ((UCSRB & 0x002) << 7);
				u16ReturnLoc |= UDR;
				return u16ReturnLoc;
				break;

			default :
				return UDR;
				break;
			}
		}
		break;
	}
}

void  __vector_14(void) __attribute__((signal,used)); // It is volatile called by hardware not software
void  __vector_14(void)
{
	USART_voidTransmitInterrupt();
}

