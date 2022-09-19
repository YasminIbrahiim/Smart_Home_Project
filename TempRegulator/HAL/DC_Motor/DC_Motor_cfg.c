/*
 * DC_Motor_cfg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Nourhan
 */
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "DC_Motor_cfg.h"
#include "DC_Motor_priv.h"


tstrDCMotorCfg DC_Motor_astrPinMapping[DC_Motor_MAX_NUM]={

	{ DC_Motor_intSupply, .u8DioPinCfg.u8inpSupply = {DC_Motor_u8POS,  DC_Motor_u8NEG , DIO_u8PIN_4  ,DIO_u8PIN_6 } } ,
	{ DC_Motor_extSupply, .u8DioPinCfg.u8extSupply =  {DC_Motor_u8extHIGH, DC_Motor_u8NEG ,DIO_u8PIN_5}  }

};

