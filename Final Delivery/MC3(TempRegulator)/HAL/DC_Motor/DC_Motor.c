#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "DC_Motor.h"

#include "DC_Motor_cfg.h"
#include "DC_Motor_priv.h"

uint8 init = 0;

void DC_Motor_voidInit(void)
{
	uint8 u8CntrLoc ;
	init = 1;
	for (u8CntrLoc = 0 ; u8CntrLoc < DC_Motor_MAX_NUM ; u8CntrLoc++)
	{
		switch( (DC_Motor_astrPinMapping[u8CntrLoc].u8PinNumbers) )
		{
		case DC_Motor_intSupply:
			if(DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Map >= DIO_u8PIN_0  &&
					DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Map <= DIO_u8PIN_31 &&
					DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin2Map >= DIO_u8PIN_0  &&
					DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin2Map <= DIO_u8PIN_31)
			{
				if(DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Connect != DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Connect)
				{
					if(DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8extHIGH ||
					   DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8extLOW	)
					{
						//no error
					}
					else
					{
						DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}


				}
				else
				{
					DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_CONFIG_PARM_ERROR;
				}
			}
			else
			{
				DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
			}
		break;

		case DC_Motor_extSupply:
			if(DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinMap >= DIO_u8PIN_0  &&

					DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinMap <= DIO_u8PIN_31)
			{
				if(DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8extHIGH ||
				   DC_Motor_astrPinMapping[u8CntrLoc].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8extLOW	)
				{
					//no error
				}
				else
				{
					DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_CONFIG_PARM_ERROR;
				}
			}
			else
			{
				DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_PARAM_OUT_OF_RANGE;
			}

		break;

		default:
			DC_Motor_astrPinMapping[u8CntrLoc].tenuDCMotor_ErrorState = E_NOK_CONFIG_PARM_ERROR;
		break;
		}

	}

}
tenuErrorStatus DC_Motor_enuState (uint8 u8DC_MotorNumCpy , uint8 u8Mode)
{
	tenuErrorStatus DC_ErrorState = E_OK;

	switch (u8Mode) {
		case DC_Motor_forward:
			switch(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8PinNumbers)
			{
				case DC_Motor_intSupply:
				{
					if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8POS)
					{
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8HIGH);
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8LOW);
					}
					else if (DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8NEG)
					{
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8LOW);
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8HIGH);

					}
					else
					{
						DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}
				}
				break;

				case DC_Motor_extSupply:
				{
					if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extHIGH)
					{
						if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8NEG)
						{
							DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8LOW);
						}
						else
						{
							DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
						}
					}
					else if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extLOW)
					{
						if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8POS)
						{
							DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8HIGH);

						}
					}
					else
					{
						DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}
				}
				break;
			}
		break;

		case DC_Motor_backward:
		{
			switch(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8PinNumbers)
			{
				case DC_Motor_intSupply:
				{
					if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8POS)
					{
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8LOW);
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8HIGH);
					}
					else if (DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Connect == DC_Motor_u8NEG)
					{

						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8HIGH);
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8LOW);
					}
					else
					{
						DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}
				}
				break;
				case DC_Motor_extSupply:
				{

					if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extHIGH)
					{
						if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8POS)
						{
							DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8LOW);
						}
						else
						{
							//error
						}
					}
					else if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extLOW)
					{
						if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinConnect == DC_Motor_u8NEG)
						{
							DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8HIGH);

						}
					}
					else
					{
						DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}
				}
				break;
				default:
					DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
				}
				break;
		}
		case DC_Motor_off:
			switch(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8PinNumbers)
			{
				case DC_Motor_intSupply:
				{
					DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin1Map, DIO_u8LOW);
					DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8inpSupply.u8Pin2Map, DIO_u8LOW);
				}
				break;
				case DC_Motor_extSupply:
				{
					if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extHIGH)
					{
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8HIGH);
					}
					else if(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8SupplyType == DC_Motor_u8extLOW)
					{
						DIO_enuWritePin(DC_Motor_astrPinMapping[u8DC_MotorNumCpy].u8DioPinCfg.u8extSupply.u8PinMap, DIO_u8LOW);
					}
					else
					{
						DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
					}
				}
				break;
				default:
					DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
				break;

			}
			break;

		default:
			DC_ErrorState = E_NOK_CONFIG_PARM_ERROR;
		break;
	}


	return DC_ErrorState;
}
