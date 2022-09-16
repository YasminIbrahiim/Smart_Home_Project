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





}
void I2C_voidMasterTransmit(uint8 u8SlaveAddressCpy, uint8 * pu8DataCpy, uint8 u8DataSizeCpy)
{
	uint8 u8CntrLoc;
	if(pu8DataCpy != NULL_PTR)
	{
		/*Step 1 Send Start Condition*/
		SET_BIT(TWCR,2);
		CLR_BIT(TWCR,4);
		SET_BIT(TWCR,5);
		SET_BIT(TWCR,7);
		while(GET_BIT(TWCR,7) == 0);
		if(TWSR == MASTER_START_CONDITION_TRANSMITTED)
		{
			/*Step 2 Send SLA+W*/
			TWDR = u8SlaveAddressCpy; // Writing Slave Address
			CLR_BIT(TWDR,0); // Inform slave this is Write Operation
			SET_BIT(TWCR,7);// Send SLA+W
		}
		else
		{
			//DIO_enuWritePin(DIO_u8PIN_0,DIO_u8LOW);

		}
		while(!GET_BIT(TWCR,7)); // Waiting to Receive ACK from targeted Slave
		if(TWSR == MASTER_SLA_W_TRASMITTED_ACK_RECEIVED)
		{
			/*Step 3 Send Data*/
			for(u8CntrLoc = 0 ; u8CntrLoc <u8DataSizeCpy ;  u8CntrLoc++)
			{
				TWDR = pu8DataCpy[u8CntrLoc];
				TWCR = MASTER_SEND_DATA;
				while(!GET_BIT(TWCR,7));
				if(TWSR == MASTER_DATA_TRANSMITTED_ACK_RECEIVED)
				{
					continue;
				}
				else if(TWSR == MASTER_DATA_TRANSMITTED_NO_ACK_RECEIVED)
				{
					break;
				}
				else
				{
					break;
				}
			}

		}
		else if(TWSR == MASTER_SLA_W_TRASMITTED_NO_ACK_RECEIVED)
		{
			/*Send Repeated Start Condition*/

		}
		else if(TWSR == MASTER_ARBITRATION_LOST)
		{
			return;
		}
		else
		{
			return;
		}

	}
	else
	{
		return;
	}


}
uint8 I2C_u8SlaveReceive(void)
{
	uint8 u8ReturnLoc;
	SET_BIT(TWCR,2);
	CLR_BIT(TWCR,4);
	CLR_BIT(TWCR,5);
	SET_BIT(TWCR,6);
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	SET_BIT(TWCR,7);
	while(!GET_BIT(TWCR,7));
	u8ReturnLoc = TWDR;
	return u8ReturnLoc;
}
