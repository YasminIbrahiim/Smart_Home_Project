
#ifndef __UART_INTERFACE_H__
#define __UART_INTERFACE_H__


void UART_voidInit(void);

void UART_voidSendByteSynch(uint8 Copy_u8Byte);

uint8 UART_voidRecieveByteSynch(uint16 Copy_u16Timeout);

#endif
