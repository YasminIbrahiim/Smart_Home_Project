/*
 * BUTTON_cfg.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Nourhan
 */
#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "BUTTON_cfg.h"
#include "BUTTON_priv.h"


tstrButtonCfg Button_astrButtonPinMapping[BUTTON_MAX_NUM]={

	{DIO_u8PIN_26 , BUTTON_u8PullUp },
	{DIO_u8PIN_27 , BUTTON_u8PullUp },
	{DIO_u8PIN_10 , BUTTON_u8PullUp },
	{DIO_u8PIN_22 , BUTTON_u8PullDown },
	{DIO_u8PIN_31 , BUTTON_u8PullDown }

};

