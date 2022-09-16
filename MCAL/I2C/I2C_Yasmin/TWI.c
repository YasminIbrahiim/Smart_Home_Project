/********************************************/
/* Description : TWI/I2C Driver             */
/* Author      : Yasmin Mohamed             */
/* Date        : 11/9/2022                  */
/* Version     : 0.1V                       */
/********************************************/

#define "STD_Types.h"
#define "BIT_MATH.h"

#define "TWI.h"
#define "TWI_cfg.h"
#define "TWI_priv.h"

uint8 u8SCLfreq; 
pf pfISR_CallBack;

void TWI_voidInit(void)
{
	SET_BIT(TWCR , 2);
}
uint8 TWI_u8ClkFrequencyCalculator(uint8 u8PrescalerCpy , uint8 u8BitRateCpy )                /*   ???     */
{
	TWBR = uint8 u8BitRateCpy;
	u8SCLfreq = F_CPU / (16 + (2 * TWBR * u8PrescalerCpy) );
	return u8SCLfreq;
}
void TWI_voidMasterTransmitSync(uint8 u8SlaveAddressCpy , uint8 u8DataCpy)
{
	SET_BIT(TWCR , 5);
	while(GET_BIT(TWCR , 7) == 0);
	if(TWSR & 0xF8 == 0x08)
	{
		TWDR = u8SlaveAddressCpy << 1;
		SET_BIT(TWCR , 7);
		CLR_BIT(TWCR , 5);
		while(GET_BIT(TWCR , 7) == 0);
		if(TWSR & 0xF8 == 0x18)
		{
			SET_BIT(TWCR , 7);
			TWDR = uint8 DataCpy;
			while(GET_BIT(TWCR , 7) == 0);
			if(TWSR & 0xF8 == 0x28)
			{
				SET_BIT(TWCR , 7);
				SET_BIT(TWCR , 4);
			}
			else
			{
				SET_BIT(TWCR , 4);
			}
		}
		else
		{
			SET_BIT(TWCR , 4);
		}
	}
	else
	{
		SET_BIT(TWCR , 4);
	}
	
}
void TWI_voidMasterTransmitAsync(uint8 u8SlaveAddressCpy , uint8 u8DataCpy)
{
	
}
tenuErrorStatus TWI_u8MasterRecieveSync(uint8 u8SlaveAddressCpy , uint8 *pu8ReadDataCpy)
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	SET_BIT(TWCR , 5);
	while(GET_BIT(TWCR , 7) == 0);
	if(TWSR & 0xF8 == 0x08)
	{
		TWDR = u8SlaveAddressCpy << 1;
		SET_BIT(TWCR , 7);
		CLR_BIT(TWCR , 5);
		while(GET_BIT(TWCR , 7) == 0);
		if(TWSR & 0xF8 == 0x40)
		{
			SET_BIT(TWCR , 6);
			while(GET_BIT(TWCR , 7) == 0);
			if(TWSR & 0xF8 == 0x50)
			{
				if(pu8ReadDataCpy == == NULL_PTR)
			{
					tReturnErrorStatusLOC = E_NOK_PARAM_NULL_POINTER;
			}
			else
			{
					*pu8ReadDataCpy = TWDR;
					CLR_BIT(TWCR , 6);
					SET_BIT(TWCR , 4);
			}
			}
			else
			{
				tenuErrorStatus tReturnErrorStatusLOC = E_NOK;
				SET_BIT(TWCR , 4);
			}
		}
		else
		{
			tenuErrorStatus tReturnErrorStatusLOC = E_NOK;
			SET_BIT(TWCR , 4);
		}
		
	}
	else
	{
		tenuErrorStatus tReturnErrorStatusLOC = E_NOK;
		SET_BIT(TWCR , 4);
	}
}
tenuErrorStatus TWI_u8MasterRecieveAsync(uint8 *pu8ReadDataCpy)
{
	
}
void TWI_voidSlaveTransmitSync(uint8 u8DataCpy)
{
	while(GET_BIT(TWCR , 7) == 0);
	if(TWSR & 0xF8 == 0xA8)
	{
		TWDR = u8DataCpy;
		SET_BIT(TWCR , 7);
			if(TWSR & 0xF8 == 0xB8)
			{
				
			}
			else
			{
				SET_BIT(TWCR , 7);
				SET_BIT(TWCR , 4);
			}
	}
	else
	{
		SET_BIT(TWCR , 4);
	}
}
void TWI_voidSlaveTransmitAsync(uint8 DataCpy)
{
	
}
tenuErrorStatus TWI_u8SlaveRecieveSync(uint8 *pu8ReadDataCpy)
{
	tenuErrorStatus tReturnErrorStatusLOC = E_OK;
	SET_BIT(TWCR , 6);
	while(GET_BIT(TWCR , 7) == 0);
	if(TWSR & 0xF8 == 0x60)
	{
		if(pu8ReadDataCpy == == NULL_PTR)
		{
			tReturnErrorStatusLOC = E_NOK_PARAM_NULL_POINTER;
			SET_BIT(TWCR , 4);
		}
		else
		{
			*pu8ReadDataCpy = TWDR;
			 SET_BIT(TWCR , 7);
			 SET_BIT(TWCR , 4);
		}

	}
	else
	{
		tenuErrorStatus tReturnErrorStatusLOC = E_OK;
		SET_BIT(TWCR , 4);
	}
	
}
tenuErrorStatus TWI_u8SlaveRecieveAsync(uint8 *pu8ReadDataCpy)
{
	
}
void TWI_voidInterruptEnable(void)
{
	SET_BIT(TWCR , 0);
}
void TWI_voidInterruptDisable(void)
{
	CLR_BIT(TWCR , 0);
}
void TWI_VoidTWIInterruptCallBack(pf pfCallBackcpy)
{
	pfISR_CallBack = pfCallBackcpy;
}
void __vector_19(void) __attribute__((signal, used));
void __vector_19(void)
{
	pfISR_CallBack();
}