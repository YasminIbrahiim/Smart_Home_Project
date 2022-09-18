/*
 * EEPROM.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Moaz
 */

#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"


#include "I2C.h"
#include "I2C_priv.h"
#include "EEPROM.h"
#include "EEPROM_cfg.h"

void EEPROM_voidWrite(uint8 u8AddressCpy , uint8 u8DataCpy , uint8 *u8BoolWritten)
{
	uint8 u8CurrentStatus = 0;
	TWI_voidStart();
	u8CurrentStatus = TWI_u8Get_Status();
	{
		if(u8CurrentStatus == MASTER_START_CONDITION_TRANSMITTED)
		{
			// Masking SLA + W , so CLR Last Bit
			TWI_voidWrite(EEPROM_ADDRESS|EEPROM_WRITE);

		}
		else
		{
			return ;
		}
		u8CurrentStatus = TWI_u8Get_Status();
		{
			if(u8CurrentStatus == MASTER_SLA_W_TRASMITTED_ACK_RECEIVED)
			{
					/*Write Address In EEPROM*/
					TWI_voidWrite(u8AddressCpy);
					u8CurrentStatus = TWI_u8Get_Status();
					if(u8CurrentStatus ==MASTER_DATA_TRANSMITTED_ACK_RECEIVED)
					{
						/*If ACK Received, We Send the date to be written*/
						TWI_voidWrite(u8DataCpy);
						TWI_voidStop();
						*u8BoolWritten = 0x01;
						return;
					}
					else if(u8CurrentStatus == MASTER_DATA_TRANSMITTED_NO_ACK_RECEIVED)
					{
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


	}
}

void EEPROM_voidRead(uint8 u8AddressCpy, uint8 *u8DataCpy)
{
	uint8 u8CurrentStatus = 0;
    /* Send the Start Bit */
    TWI_voidStart();
    u8CurrentStatus = TWI_u8Get_Status();
    {
    	if(u8CurrentStatus == MASTER_START_CONDITION_TRANSMITTED)
    	{
    		// Masking SLA + W , so CLR Last Bit
    		TWI_voidWrite(EEPROM_ADDRESS|EEPROM_WRITE);
    	}
    	else
    	{
    		return;
    	}
    }
    u8CurrentStatus = TWI_u8Get_Status();
	{
		if(u8CurrentStatus == MASTER_SLA_W_TRASMITTED_ACK_RECEIVED)
		{
				/*Write Address In EEPROM*/
				TWI_voidWrite(u8AddressCpy);
				u8CurrentStatus = TWI_u8Get_Status();
				if(u8CurrentStatus ==MASTER_DATA_TRANSMITTED_ACK_RECEIVED)
				{
					/*If ACK Received, We Send Repeated Start*/
					TWI_voidStart();
					u8CurrentStatus = TWI_u8Get_Status();
					if(u8CurrentStatus == MASTER_REPEATED_START_CONDITION_TRANSMITTED)
					{
						// Masking SLA + R , so CLR Last Bit

						 TWI_voidWrite(EEPROM_ADDRESS|EEPROM_READ);

						 u8CurrentStatus = TWI_u8Get_Status();

						 if(u8CurrentStatus == MASTER_SLA_R_TRANSMITTED_ACK_RECEIVED)
						 {

							 *u8DataCpy = TWI_u8Read_NACK();
							 u8CurrentStatus = TWI_u8Get_Status();
							 if(u8CurrentStatus == MASTER_DATA_RECEIVED_NO_ACK_RETURNED)
							 {
								 TWI_voidStop();
								 return;
							 }
							 else if(u8CurrentStatus == MASTER_DATA_RECEIVED_ACK_RETURNED)
							 {

								 return;
							 }

						 }
						 else if(u8CurrentStatus == MASTER_SLA_R_TRANSMITTED_NO_ACK_RECEIVED)
						 {

							 return;
						 }
						 else
						 {

						 }
					}
					else
					{
						//DIO_enuWritePin(DIO_u8PIN_1,DIO_u8HIGH);
						*u8DataCpy = u8CurrentStatus;
						return;
					}

				}
				else if(u8CurrentStatus == MASTER_DATA_TRANSMITTED_NO_ACK_RECEIVED)
				{
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

}
