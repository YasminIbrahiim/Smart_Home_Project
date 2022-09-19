#ifndef   I2C_priv_H
#define   I2C_priv_H


typedef enum
{
	E_Done,
	NULL_Ptr_Error,
	StartConditionError,
	RepeatedStartConditionError,
	SLA_W_Error,
	SLA_R_Error,
	TransDataError,
	ReceiveDataError,
	StopConditionError,
	NO_Data_Received
	
}tenuErrorState;

#define    TWCR  *((volatile uint8*)0x56)
#define    TWDR  *((volatile uint8*)0x23)
#define    TWAR  *((volatile uint8*)0x22)
#define    TWSR  *((volatile uint8*)0x21)
#define    TWBR  *((volatile uint8*)0x20)


#define  GENERAL_CALL_ACTIVATED			((uint8) 0x01)
#define  GENERAL_CALL_DEACTIVATED		((uint8) 0x00)


#define  INTERRUPT_ENABLED				((uint8) 0x01)
#define  INTERRUPT_DISABLED				((uint8)0x00)

#define    ENABLE_ACK_FLAG              0
#define    DISABLE_ACK_FLAG             1

#define    ENABLE_MASTER_MODE           ((uint8) 0x01)
#define    ENABLE_SLAVE_MODE            ((uint8) 0x02)

#define    SET_PRESCALER_1              ((uint8) 0x04)
#define    SET_PRESCALER_4              ((uint8) 0x05)
#define    SET_PRESCALER_16             ((uint8) 0x06)
#define    SET_PRESCALER_64             ((uint8) 0x07)

/* Master transmitter mode     */
#define    MASTER_START_CONDITION_TRANSMITTED                              0x08
#define    MASTER_REPEATED_START_CONDITION_TRANSMITTED                     0x10
#define    MASTER_SLA_W_TRASMITTED_ACK_RECEIVED                            0x18
#define    MASTER_SLA_W_TRASMITTED_NO_ACK_RECEIVED                         0x20            
#define    MASTER_DATA_TRANSMITTED_ACK_RECEIVED                            0x28
#define    MASTER_DATA_TRANSMITTED_NO_ACK_RECEIVED                         0x30
#define    MASTER_ARBITRATION_LOST                                         0x38
 
/*Master Receiver mode  */                                                 
#define    MASTER_SLA_R_TRANSMITTED_ACK_RECEIVED                           0x40
#define    MASTER_SLA_R_TRANSMITTED_NO_ACK_RECEIVED                        0x48
#define    MASTER_DATA_RECEIVED_ACK_RETURNED                               0x50
#define    MASTER_DATA_RECEIVED_NO_ACK_RETURNED                            0x58
  
/*Slave Receiver mode */                                                   
#define    SLAVE_SLA_W_RECEIVED_ACK_RETURNED                               0x60
#define    SLAVE_ARBITRARION_LOST_AFTER_SLA_W_RECEIVED                     0x68
#define    SLAVE_GENERAL_CALL_RECEIVED_ACK_RETURNED                        0x70
#define    SLAVE_ARBITRARION_LOST_AFTER_GENERAL_CALL_ADDRESS_RECEIVED      0x78
#define    SLAVE_DATA_RECEIVED_ACK_RETURNED                                0x80
#define    SLAVE_DATA_RECEIVED_NO_ACK_RETURNED	                           0x88
#define    SLAVE_GENERAL_CALL_DATA_RECEIVED_ACK_RETURNED                   0x90
#define    SLAVE_GENERAL_CALL_DATA_RECEIVED_NO_ACK_RETURNED                0x98
#define    SLAVE_STOP_CONDITION_RECIEVED                                   0xA0

/*Slave Transmitter mode */
#define    SLAVE_SLA_R_RECEIVED_ACK_RETURNED                               0xA8
#define    SLAVE_ARBITRARION_LOST_AFTER_SLA_R_RECEIVED                     0xB0
#define    SLAVE_DATA_TRANSMITTED_ACK_RECEIVED                             0xB8
#define    SLAVE_DATA_TRANSMITTED_NO_ACK_RECEIVED                          0xC0
#define    SLAVE_LAST_DATA_TRANSMITTED                                     0xC8 


#define		MASTER_SEND_START_CONDITION		((uint8) 0xA4)
#define 	MASTER_SEND_SLA_W				((uint8) 0x84)
#define		MASTER_SEND_DATA				((uint8) 0x84)


#define SLAVE_WAIT_FOR_ADDRESSED			((uint8) 0x44)

#define SLAVE_READ_ACK						((uint8) 0x00)


#define F_CPU	(8000000)




#endif
