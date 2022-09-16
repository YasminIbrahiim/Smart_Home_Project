
#ifndef USART_PRIV_H
#define USART_PRIV_H



#define UCSRA					*((volatile uint8 *) 0x2B)
#define UCSRB					*((volatile uint8 *) 0x2A)
#define UCSRC					*((volatile uint8 *) 0x40)

#define UBBRH					*((volatile uint8 *) 0x40)
#define UBBRL					*((volatile uint8 *) 0x29)

#define UDR						*((volatile uint8 *) 0x2C)


#define UART_MODE				((uint8) 0x00)
#define USRT_MODE				((uint8) 0x01)


#define POLLING_BASED			((uint8) 0x1F)
#define INTERRUPT_BASED			((uint8) 0xFF)

#define TRANSMIT_ONLY			((uint8) 0x00)
#define RECEIVE_ONLY			((uint8) 0x01)
#define TRANSMIT_RECEIVE		((uint8) 0x02)


#define CHAR_SIZE_5_BITS		((uint8) 0x00)
#define CHAR_SIZE_6_BITS		((uint8) 0x01)
#define CHAR_SIZE_7_BITS		((uint8) 0x02)
#define CHAR_SIZE_8_BITS		((uint8) 0x03)
#define CHAR_SIZE_9_BITS		((uint8) 0x04)

#define SYNC_TRising_RFalling	((uint8) 0x00)
#define SYNC_TFalling_TRising	((uint8) 0x01)

#define BAUD_RATE_2400			((uint8) 0x00)
#define BAUD_RATE_4800			((uint8) 0x01)
#define BAUD_RATE_9600			((uint8) 0x02)

#define DOUBLE_SPEED_ENABLE		((uint8) 0x00)
#define DOUBLE_SPEED_DISABLE	((uint8) 0x01)

#define PARITY_DISABLED			((uint8) 0x00)
#define PARITY_EVEN				((uint8) 0x01)
#define PARITY_ODD				((uint8) 0x02)



#define ONE_STOPPING_BIT		((uint8) 0x00)
#define TWO_STOPPING_BITS		((uint8) 0x01)


#define FOSC					((uint32) 8000000)


#endif
