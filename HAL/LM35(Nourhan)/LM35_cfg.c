/*
 * LM35_cfg.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Nourhan
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "LM35_cfg.h"
#include "LM35_priv.h"


tstrLM35Cfg LM35_astrChannelMapping[LM35_MAX_NUM] =
{
		{ADC_CHANNEL_NUM_0 , LM35_ReadSynch}
};


