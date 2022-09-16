#ifndef    UART_PRIV_H
#define    UART_PRIV_H


#define  UDR     	  *((volatile uint8*)0x2C)    
#define  UCSRA        *((volatile uint8*)0x2B)    
#define  UCSRB        *((volatile uint8*)0x2A)
#define  UCSRC        *((volatile uint8*)0x40)
#define  UBRRH        *((volatile uint8*)0x40)
#define  UBRRL        *((volatile uint8*)0x29)

#define  UART_ASYNC_U2X_DISABLE  0 
#define  UART_ASYNC_U2X_ENABLE   1       

#define UART_MULTI_PROCESSOR_C0M_MODE_DISABLE    2
#define UART_MULTI_PROCESSOR_C0M_MODE_ENABLE     3       

#define CHAR_SIZE_5    4
#define CHAR_SIZE_6    5
#define CHAR_SIZE_7    6
#define CHAR_SIZE_8    7
#define CHAR_SIZE_9    8

#define ASYNC_OPERATION    9
#define SYNC_OPERATION     10

#define DISABLE_PARITY_MODE  11
#define EVEN_PARITY_MODE     12
#define ODD_PARITY_MODE      13

#define ONE_STOP_BIT         14
#define TWO_STOP_BITS		 15

#define DISABLE_CLK              16
#define TXD_RISING_RXD_FALLING   17
#define RXD_RISING_TXD_FALLING   18

#define BAUD_RATE_U2X0_2400         ((uint16)207)
#define BAUD_RATE_U2X0_4800         ((uint16)103)
#define BAUD_RATE_U2X0_9600         ((uint16)51)
#define BAUD_RATE_U2X0_14_4K        ((uint16)34)
#define BAUD_RATE_U2X0_19_2K        ((uint16)25)
#define BAUD_RATE_U2X0_28_8K        ((uint16)16)
#define BAUD_RATE_U2X0_38_4K        ((uint16)12)
#define BAUD_RATE_U2X0_57_6K        ((uint16)8)
#define BAUD_RATE_U2X0_76_8K        ((uint16)6)
#define BAUD_RATE_U2X0_115_2K       ((uint16)3)
#define BAUD_RATE_U2X0_230_4K       ((uint16)1)
#define BAUD_RATE_U2X0_250K         ((uint16)1)
#define BAUD_RATE_U2X0_0.5M         ((uint16)0)

#define BAUD_RATE_U2X1_2400         ((uint16)416)
#define BAUD_RATE_U2X1_4800         ((uint16)207)
#define BAUD_RATE_U2X1_9600         ((uint16)103)
#define BAUD_RATE_U2X1_14_4K        ((uint16)68)
#define BAUD_RATE_U2X1_19_2K        ((uint16)51)
#define BAUD_RATE_U2X1_28_8K        ((uint16)34)
#define BAUD_RATE_U2X1_38_4K        ((uint16)25)
#define BAUD_RATE_U2X1_57_6K        ((uint16)16)
#define BAUD_RATE_U2X1_76_8K        ((uint16)12)
#define BAUD_RATE_U2X1_115_2K       ((uint16)8)
#define BAUD_RATE_U2X1_230_4K       ((uint16)3)
#define BAUD_RATE_U2X1_250K         ((uint16)3)
#define BAUD_RATE_U2X1_0.5M			((uint16)1)	 


#endif
