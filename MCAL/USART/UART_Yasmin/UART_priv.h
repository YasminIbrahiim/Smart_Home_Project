#ifndef UART_PRIV_H
#define UART_PRIV_H

#define   UART_ASYNC_MODE                   0      
#define   UART_SYNC_MODE                    1
								            
								            
#define   UART_RISING_TX_FALLING_RX         0
#define   UART_FALLING_TX_RISING_RX         1

#define   UART_CHAR_SIZE_5                  4          
#define   UART_CHAR_SIZE_6                  5
#define   UART_CHAR_SIZE_7                  6
#define   UART_CHAR_SIZE_8                  7
#define   UART_CHAR_SIZE_9                  8

#define   UART_DISABLED_PARITYD_MODE        0
#define   UART_RESERVED_PARITY_MODE         1
#define   UART_EVEN_PARITY_MODE             2
#define   UART_ODD_PARITY_MODE              3

#define   UART_ONE_STOP_BIT                 0
#define   UART_TWO_STOP_BIT                 1

#define   UART_BAUD_RATE_U2X0_2400          ((uint16)207)
#define   UART_BAUD_RATE_U2X0_4800          ((uint16)103)
#define   UART_BAUD_RATE_U2X0_9600          ((uint16)51)
#define   UART_BAUD_RATE_U2X0_14_4K         ((uint16)34)
#define   UART_BAUD_RATE_U2X0_19_2K         ((uint16)25)
#define   UART_BAUD_RATE_U2X0_28_8K         ((uint16)16)
#define   UART_BAUD_RATE_U2X0_38_4K         ((uint16)12)
#define   UART_BAUD_RATE_U2X0_57_6K         ((uint16)8)
#define   UART_BAUD_RATE_U2X0_76_8K         ((uint16)6)
#define   UART_BAUD_RATE_U2X0_115_2K        ((uint16)3)
#define   UART_BAUD_RATE_U2X0_230_4K        ((uint16)1)
#define   UART_BAUD_RATE_U2X0_250K          ((uint16)1)
#define   UART_BAUD_RATE_U2X0_0.5M          ((uint16)0)
										    
#define   UART_BAUD_RATE_U2X1_2400          ((uint16)416)
#define   UART_BAUD_RATE_U2X1_4800          ((uint16)207)
#define   UART_BAUD_RATE_U2X1_9600          ((uint16)103)
#define   UART_BAUD_RATE_U2X1_14_4K         ((uint16)68)
#define   UART_BAUD_RATE_U2X1_19_2K         ((uint16)51)
#define   UART_BAUD_RATE_U2X1_28_8K         ((uint16)34)
#define   UART_BAUD_RATE_U2X1_38_4K         ((uint16)25)
#define   UART_BAUD_RATE_U2X1_57_6K         ((uint16)16)
#define   UART_BAUD_RATE_U2X1_76_8K         ((uint16)12)
#define   UART_BAUD_RATE_U2X1_115_2K        ((uint16)8)
#define   UART_BAUD_RATE_U2X1_230_4K        ((uint16)3)
#define   UART_BAUD_RATE_U2X1_250K          ((uint16)3)
#define   UART_BAUD_RATE_U2X1_0.5M			((uint16)1)


#define   UDR     	                        *((volatile uint8*)0x2C)
#define   UCSRC                             *((volatile uint8*)0x40)
#define   UBRRH                             *((volatile uint8*)0x40)
#define   UBRRL                             *((volatile uint8*)0x29)
#define   UCSRB                             *((volatile uint8*)0x2A)
#define   UCSRA                             *((volatile uint8*)0x2B)
 


#endif