#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include "I2C.h"
#include "I2C_cfg.h"
#include "I2C_priv.h"

#include <avr/delay.h>


void I2C_voidInit(void)
{
	TWCR = 0x00;
	TWAR = 0x00;
	TWBR = 0x00;
	TWSR = 0x00;
	/*Activating Pull Up Registers For SCL , SDA Pins*/
	TWAR = SLAVE_MODE_ADDRESS;
	switch(OPERATION_MODE)
	{
	case ENABLE_MASTER_MODE:

		/* Set prescaler value */
		switch(PRESCALER_VALUE)
		{
		case SET_PRESCALER_1:
			CLR_BIT(TWSR, 0);
			CLR_BIT(TWSR, 1);
	         TWBR = (uint8)(((float)F_CPU / (2.0 * 100000)) - 8);
			break;
		case SET_PRESCALER_4:
			SET_BIT(TWSR, 0);
			CLR_BIT(TWSR, 1);
			TWBR = (uint8)(((float)F_CPU / (8.0 * 100000)) - 2);
			break;
		case SET_PRESCALER_16:
			CLR_BIT(TWSR, 0);
			SET_BIT(TWSR, 1);
			TWBR = (uint8)(((float)F_CPU / (32 * 100000)) - 0.5);
			break;
		case SET_PRESCALER_64:
			SET_BIT(TWSR, 0);
			SET_BIT(TWSR, 1);
			TWBR = (uint8)(((float)F_CPU / (128 * 100000)) - 0.125);
			break;
		}
		break;
	case ENABLE_SLAVE_MODE:
		break;
	}

	DIO_enuPullWrite(DIO_u8PIN_16 , DIO_u8ACTIVATE);
	DIO_enuPullWrite(DIO_u8PIN_17 , DIO_u8ACTIVATE);
	switch(INTERRUPT_MODE)
	{
	case INTERRUPT_ENABLED:
		SET_BIT(TWCR,0);
		break;
	case INTERRUPT_DISABLED:
		CLR_BIT(TWCR,0);
		break;

	}
	SET_BIT(TWCR,2); // Enable Bit
	SET_BIT(TWCR,6); // TWI Enable ACK (To ACK if SLA + R/W Received)


}

void I2C_voidMasterTransmit(uint8 u8SlaveAddressCpy, uint8 * pu8DataCpy, uint8 u8DataSizeCpy)
{
	uint8 u8CntrLoc;
	uint8 u8CurrentStatus = 0;
	TWI_voidStart();
	u8CurrentStatus = TWI_u8Get_Status();
	{
		if(u8CurrentStatus == MASTER_START_CONDITION_TRANSMITTED)
		{
			u8SlaveAddressCpy &= 0xFE; // Masking SLA + W , so CLR Last Bit
			TWI_voidWrite(u8SlaveAddressCpy);
		}
		else
		{
			return ;
		}
	}
	u8CurrentStatus = TWI_u8Get_Status();
	{
		if(u8CurrentStatus == MASTER_SLA_W_TRASMITTED_ACK_RECEIVED)
		{
			for(u8CntrLoc = 0 ; u8CntrLoc < u8DataSizeCpy; u8CntrLoc++)
			{
				TWI_voidWrite(pu8DataCpy[u8CntrLoc]);
				u8CurrentStatus = TWI_u8Get_Status();
				if(u8CurrentStatus ==MASTER_DATA_TRANSMITTED_ACK_RECEIVED)
				{
					continue;
				}
				else if(u8CurrentStatus == MASTER_DATA_TRANSMITTED_NO_ACK_RECEIVED)
				{
					continue;
				}
				else if(u8CurrentStatus == MASTER_ARBITRATION_LOST)
				{
					/*Bus is Released*/
					return;
				}
				else
				{
					return;
				}
			}
		}
		else if(u8CurrentStatus == MASTER_SLA_W_TRASMITTED_NO_ACK_RECEIVED)
		{
			/*We May Send Data Or Repeated Start Or Stop Condition */
			return;
		}
		else if(u8CurrentStatus == MASTER_ARBITRATION_LOST)
		{
			/*Bus is Released*/
			return;
		}
		else
		{
			return;
		}
	}

	TWI_voidStop();

}


void I2C_voidSlaveReceive(uint8 *pu8DataCpy, uint8 u8ArraySizeCpy)
{
		uint8 u8CtrLOC;
		CLR_BIT(TWCR,4);
		CLR_BIT(TWCR,5);
		SET_BIT(TWCR,6); //enable ack
		SET_BIT(TWCR,7); //clear interrupt flag

		while(!GET_BIT(TWCR,7));
		for(u8CtrLOC = 0 ; u8CtrLOC < u8ArraySizeCpy ; u8CtrLOC++)
		{
			pu8DataCpy[u8CtrLOC] = TWI_u8Read_ACK();
		}

		SET_BIT(TWCR,7);

}


void TWI_voidStart(void)
{
	//SET_BIT(TWCR,2); // TWI Enable Pin
	CLR_BIT(TWCR,4); // TWI Disable Stop Condition
	SET_BIT(TWCR,5); // TWI Enable Start Condition
	SET_BIT(TWCR,7); // Clear TWINT Flag
	while(GET_BIT(TWCR,7) == 0); // Wait for TWINT Flag to be Set (Start/Repeated Start Condition Sent Successfully)
}


void TWI_voidStop(void)
{
	SET_BIT(TWCR,2); //TWI Enable Pin
	SET_BIT(TWCR,4); // TWI Enable Stop Condition
	CLR_BIT(TWCR,5); // TWI Disable Start Condition
	SET_BIT(TWCR,7); // Clear TWINT Flag
}

void TWI_voidWrite(uint8 u8DataCpy)
{
	/* TWI_Start Must Be Called*/
	TWDR = u8DataCpy;

	SET_BIT(TWCR,2); // TWI Enable Pin
	SET_BIT(TWCR,7); // Clear TWINT Flag
	while(GET_BIT(TWCR,7) == 0); // Wait for TWINT Flag to be Set (Data Sent Successfully)
}

uint8 TWI_u8Read_ACK(void)
{
	uint8 u8ReturnLoc = 0;
	SET_BIT(TWCR,2); // TWI Enable Pin
	SET_BIT(TWCR,6); // TWI Enable ACK
	SET_BIT(TWCR,7); // Clear TWINT Flag

	while(GET_BIT(TWCR,7) == 0); // Wait for TWINT Flag to be Set (Data Received Successfully)
	u8ReturnLoc = TWDR;
	return u8ReturnLoc;
}

uint8 TWI_u8Read_NACK(void)
{
	uint8 u8ReturnLoc = 0;
	SET_BIT(TWCR,2); // TWI Enable Pin
	CLR_BIT(TWCR,6); // TWI Disable ACK
	SET_BIT(TWCR,7); // Clear TWINT Flag
	while(GET_BIT(TWCR,7) == 0); // Wait for TWINT Flag to be Set (Data Received Successfully)
	u8ReturnLoc = TWDR;
	return u8ReturnLoc;
}

uint8 TWI_u8Get_Status(void)
{
	uint8 u8ReturnStatusLoc = 0;
	u8ReturnStatusLoc = (TWSR & 0xF8);
	return u8ReturnStatusLoc;
}
