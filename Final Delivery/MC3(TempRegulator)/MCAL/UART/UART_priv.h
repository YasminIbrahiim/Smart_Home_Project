#ifndef __UART_PRIVATE_H__
#define __UART_PRIVATE_H__

/*=================================================================================
 * UART Registers
 *=================================================================================*/

#define UDR    (*(volatile uint8 *)(0x2C))
#define UCSRA  (*(volatile uint8 *)(0x2B))
#define UCSRB  (*(volatile uint8 *)(0x2A))
#define UCSRC  (*(volatile uint8 *)(0x40))
#define UBRRL  (*(volatile uint8 *)(0x29))
#define UBRRH  (*(volatile uint8 *)(0x40))

/*=================================================================================
 * UART Modes
 *=================================================================================*/

#define UART_DISABLED            0
#define UART_ENABLED             1

#define UART_ASYNCHRONOUS        0
#define UART_SYNCHRONOUS         1

#define UART_EVEN_PARITY         2
#define UART_ODD_PARITY          3

#define UART_1_STOP_BIT          0
#define UART_2_STOP_BIT          1


#define UART_5_BITS              1
#define UART_6_BITS              2
#define UART_7_BITS              3
#define UART_8_BITS              4
#define UART_9_BITS              5

#define UART_BAUDRATE_2400       207
#define UART_BAUDRATE_4800       103
#define UART_BAUDRATE_9600       51

#define UART_SAMPLE_FALLING_EDGE 0
#define UART_SAMPLE_RISING_EDGE  1

#endif
