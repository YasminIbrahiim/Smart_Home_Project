#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../HAL/LM35/LM35.h"
#include "../../HAL/RELAY/RELAY.h"

#include "Temp_cfg.h"
#include "Temp_priv.h"


tstrTempCfg Temp_astrChannelMapping[TEMP_MAX_NUM] =
{
		{TEMP_StateOFF ,  LM35_CHANNEL_NUM_0 , 0  , RELAY_u8NUM_0 , 25 , 2 }
};
