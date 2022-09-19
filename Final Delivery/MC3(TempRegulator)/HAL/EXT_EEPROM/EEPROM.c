/*
 * EEPROM.c
 *
 *  Created on: Sep 18, 2022
 *      Author: Moaz
 */

#include "../EXT_EEPROM/EEPROM.h"

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"


#include "../../MCAL/I2C/I2C.h"
#include "../../MCAL/I2C/I2C_priv.h"
#include "../EXT_EEPROM/EEPROM_cfg.h"

void EEPROM_voidWrite(uint8 u8AddressCpy , uint8 u8DataCpy)
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


					u8CurrentStatus = TWI_u8Get_Status();

					if(u8CurrentStatus == MASTER_DATA_TRANSMITTED_ACK_RECEIVED)
					{
						TWI_voidStop();
						TWI_voidStart();
						// Masking SLA + R , so CLR Last Bit

						 TWI_voidWrite(EEPROM_ADDRESS|EEPROM_READ);

						 u8CurrentStatus = TWI_u8Get_Status();

						 if(u8CurrentStatus == MASTER_SLA_R_TRANSMITTED_ACK_RECEIVED)
						 {

							 *u8DataCpy = TWI_u8Read_NACK();
							 TWI_voidStop();
							 return;

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
