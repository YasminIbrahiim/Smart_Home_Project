#ifndef UART_H
#define UART_H


void  UART_voidInit(void);
void  UART_voidTransmitSync(uint8 u8DataCpy);
void  UART_voidTransmitAsync(uint8 u8DataCpy);
uint8 UART_voidRecieveSync(void);
uint8 UART_voidRecieveAsync(void);
void UART_TxInterruptEnable(void);
void UART_TxInterruptDisable(void);
void UART_RxInterruptEnable(void);
void UART_RxInterruptDisable(void);
void UART_voidTxInterruptCallBack(pf pfTxCallBackCpy);
void UART_voidRxInterruptCallBack(pf pfRxCallBackCpy);


#endif