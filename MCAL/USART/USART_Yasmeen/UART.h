#ifndef    UART_H
#define    UART_H

tenuErrorStatus UART_enuInit(void);
void UART_VoidTxEnable(void);
void UART_VoidTxDisable(void);
void UART_voidRxEnable(void);
void UART_voidRxDisable(void);
tenuErrorStatus UART_enuReadFrameOfData(uint16* pu16ReadDataCpy);
void UART_VoidTransmitFrameOfData(uint16 u16TransmitDataCpy);
tenuErrorStatus UART_enuTransmitTrainOfData(uint16* parru16TransmitDataCpy , uint8 u8arrSizeCpy);
tenuErrorStatus UART_enuReadTrainOfData(uint16* parru16ReadDataCpy, uint8 u8arrSizeCpy );
void UART_VoidRxCompleteInterruptEnable(void);
void UART_VoidRxCompleteInterruptDisable(void);
void UART_VoidTxCompleteInterruptEnable(void);
void UART_VoidTxCompleteInterruptDisable(void);
void UART_VoidRxCompleteInterruptCallBack(pf pfRxCallBackcpy);
void UART_VoidTxCompleteInterruptCallBack(pf pfTxCallBackcpy);

#endif