
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/ADC/ADC.h"

#include "LM35.h"
#include "LM35_cfg.h"
#include "LM35_priv.h"

static float32 LM35_u16ReadTempSync(uint8 LM35_u8ChannelNum);
static float32 LM35_u16ReadTempAsync(uint8 LM35_u8ChannelNum);


float32 LM35_u16ReadTemp(uint8 LM35_u8ChannelNum)
{
	float32 f32_LM35Temp;
	LM35_u16ReadTempUpdate();
	f32_LM35Temp = LM35_astrChannelMapping[LM35_u8ChannelNum].u16ChannelValue;
	return f32_LM35Temp;
}

void LM35_u16ReadTempUpdate(void)
{
	uint8 u8Cntr;
	for(u8Cntr = 0; u8Cntr < LM35_MAX_NUM ; u8Cntr++)
	{
		if( LM35_astrChannelMapping[u8Cntr].u8ReadMode == LM35_ReadSynch)
		{
			LM35_astrChannelMapping[u8Cntr].u16ChannelValue =
					LM35_u16ReadTempSync(LM35_astrChannelMapping[u8Cntr].u8ADCChannelMap);
		}
		else if (LM35_astrChannelMapping[u8Cntr].u8ReadMode == LM35_ReadAsynch)
		{
			LM35_astrChannelMapping[u8Cntr].u16ChannelValue =
								LM35_u16ReadTempAsync(LM35_astrChannelMapping[u8Cntr].u8ADCChannelMap);
		}
		else
		{
			LM35_astrChannelMapping[u8Cntr].tenuLM35_ErrorState = E_NOK_CONFIG_PARM_ERROR ;
		}
	}
}


static float32 LM35_u16ReadTempSync(uint8 LM35_u8ChannelNum)
{
	uint16 LM35Value;
	float32 Temp = 0;

	ADC_voidSetChannel(LM35_u8ChannelNum);
	ADC_voidStartConversion();
	LM35Value = ADC_u16ReadSync();

	Temp = ( ((float)LM35Value/255.0) * 100 );

	return Temp;

}
static float32 LM35_u16ReadTempAsync(uint8 LM35_u8ChannelNum)
{
	uint16 LM35Value;
	float Temp = 0;

	ADC_voidSetChannel(LM35_u8ChannelNum);
	ADC_voidStartConversion();
	LM35Value = ADC_u16ReadASync();

	Temp = ( ((float)LM35Value/255.0) * 100 );

	return Temp;
}
