#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"

#include "RELAY.h"
#include "RELAY_cfg.h"
#include "RELAY_priv.h"
static void Relay_ONNC_OFFNO(uint8 u8RelayNumCpy , uint8 u8Mode);
static void Relay_OFFNC_ONNO(uint8 u8RelayNumCpy , uint8 u8Mode);

void Relay_voidInit(void)
{
	uint8 u8CntrLoc ;
	for (u8CntrLoc = 0 ; u8CntrLoc < RELAY_MAX_NUM  ; u8CntrLoc++)
	{
		switch( (Relay_astrPinMapping[u8CntrLoc].u8PinNumbers) )
		{
		case Relay_intSupply:
		{
			if(Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Map >= DIO_u8PIN_0  &&
			   Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Map <= DIO_u8PIN_31 &&
			   Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin2Map >= DIO_u8PIN_0  &&
			   Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin2Map <= DIO_u8PIN_31)
			{
				Relay_astrPinMapping[u8CntrLoc].tenuRelay_ErrorState = E_OK;
			}
			else
			{
				Relay_astrPinMapping[u8CntrLoc].tenuRelay_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		break;

		case Relay_extSupply:
		{
			if(Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinMap >= DIO_u8PIN_0  &&

					Relay_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinMap <= DIO_u8PIN_31)
			{

			}
			else
			{
				Relay_astrPinMapping[u8CntrLoc].tenuRelay_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
			}
		}
		break;

		default:
			Relay_astrPinMapping[u8CntrLoc].tenuRelay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
		break;
		}

	}

}


tenuErrorStatus Relay_enuState (uint8 u8RelayNumCpy , uint8 u8Mode)
{
	tenuErrorStatus Relay_ErrorState = E_OK;

	switch (u8Mode) {
		case RELAY_ON:
		{
			if(Relay_astrPinMapping[u8RelayNumCpy].u8ACMode == Relay_ACNO)
			{
				Relay_ONNC_OFFNO(u8RelayNumCpy , u8Mode);

			}
			else if(Relay_astrPinMapping[u8RelayNumCpy].u8ACMode == Relay_ACNC)
			{
				Relay_OFFNC_ONNO(u8RelayNumCpy , u8Mode);

			}
			else
			{
				Relay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			}
		}

		break;

		case RELAY_OFF:
		{
			if(Relay_astrPinMapping[u8RelayNumCpy].u8ACMode == Relay_ACNO)
			{
				Relay_OFFNC_ONNO(u8RelayNumCpy , u8Mode);

			}
			else if(Relay_astrPinMapping[u8RelayNumCpy].u8ACMode == Relay_ACNC)
			{
				Relay_ONNC_OFFNO(u8RelayNumCpy , u8Mode);

			}
			else
			{
				Relay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			}
		}

		break;

		default:
			Relay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
		break;
	}


	return Relay_ErrorState;
}


static void Relay_ONNC_OFFNO(uint8 u8RelayNumCpy , uint8 u8Mode)
{
	switch(Relay_astrPinMapping[u8RelayNumCpy].u8PinNumbers)
	{
		case Relay_intSupply:
		{

			DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8HIGH );
			DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8LOW);
		}
	break;

		case Relay_extSupply:
		{
			if(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == Relay_u8extHIGH)
			{

				DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8LOW);
			}
			else if(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == Relay_u8extLOW)
			{

				DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8HIGH);
			}
			else
			{
				Relay_astrPinMapping[u8RelayNumCpy].tenuRelay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			}
			break;
		}
	break;
	}

}

static void Relay_OFFNC_ONNO(uint8 u8RelayNumCpy , uint8 u8Mode)
{
	switch(Relay_astrPinMapping[u8RelayNumCpy].u8PinNumbers)
	{
		case Relay_intSupply:
		{
			DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8LOW);
			DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8LOW);
		}
		break;
		case Relay_extSupply:
		{
			if(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == Relay_u8extHIGH)
			{
				DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8HIGH);
			}
			else if(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == Relay_u8extLOW)
			{
				DIO_enuWritePin(Relay_astrPinMapping[u8RelayNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8LOW);
			}
			else
			{
				Relay_astrPinMapping[u8RelayNumCpy].tenuRelay_ErrorState = E_NOK_CONFIG_PARM_ERROR;
			}
			break;
		}
		break;
	}

}

