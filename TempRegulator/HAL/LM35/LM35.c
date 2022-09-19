
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/GIE/GIE.h"


#include "LM35.h"
#include "LM35_cfg.h"
#include "LM35_priv.h"

#include "../../HAL/LCD/LCD.h"

static float32 LM35_u16ReadTempSync(uint8 LM35_u8ChannelNum);
static float32 LM35_u16ReadTempAsync(uint8 LM35_u8ChannelNum);

uint8 LM35_u8Channel;

void LM35_vidInit(uint8 LM35_u8ChannelNum)
{
	LM35_u8Channel = LM35_u8ChannelNum;
	if(LM35_astrChannelMapping[LM35_u8ChannelNum].u8ReadMode == LM35_ReadSynch)
	{
		DIO_voidInit();
		ADC_voidEnable();
		ADC_voidInit();
		ADC_voidEnable();
		LCD_voidInit();
		DIO_enuPullWrite(DIO_u8PIN_0,DIO_u8HIGH);
	}
	else
	{
		DIO_voidInit();
		GIE_voidDisable();
		ADC_voidEnable();
		ADC_voidInit();
		ADC_voidEnable();
		LCD_voidInit();
		ADC_voidSetCallback(LM35_u16ReadTempUpdate);
		DIO_enuPullWrite(DIO_u8PIN_0,DIO_u8HIGH);
		ADC_voidInterruptEnable();
		GIE_voidEnable();
	}
}

float32 LM35_u16ReadTemp(uint8 LM35_u8ChannelNum)
{
	float32 f32_LM35Temp;
	if(LM35_astrChannelMapping[LM35_u8ChannelNum].u8ReadMode == LM35_ReadSynch)
	{
		f32_LM35Temp = LM35_u16ReadTempSync(LM35_u8ChannelNum);

	}
	else
	{
		f32_LM35Temp = LM35_u16ReadTempAsync(LM35_u8ChannelNum);

	}
	return f32_LM35Temp;
}

void LM35_u16ReadTempUpdate(void)
{

	if( LM35_astrChannelMapping[LM35_u8Channel].u8ReadMode == LM35_ReadSynch)
	{
		LM35_astrChannelMapping[LM35_u8Channel].f32ChannelValue =
				LM35_u16ReadTempSync(LM35_astrChannelMapping[LM35_u8Channel].u8ADCChannelMap);
	}
	else if (LM35_astrChannelMapping[LM35_u8Channel].u8ReadMode == LM35_ReadAsynch)
	{
		LM35_astrChannelMapping[LM35_u8Channel].f32ChannelValue =
							LM35_u16ReadTempAsync(LM35_astrChannelMapping[LM35_u8Channel].u8ADCChannelMap);
	}
	else
	{
		LM35_astrChannelMapping[LM35_u8Channel].tenuLM35_ErrorState = E_NOK_CONFIG_PARM_ERROR ;
	}

}


static float32 LM35_u16ReadTempSync(uint8 LM35_u8ChannelNum)
{
	uint16 LM35Value;
	float32 Temp = 0;
	ADC_voidStartConversion();

	LM35Value = ADC_u16ReadSync();


	Temp = ( (((float)LM35Value)/(1023.0*2)) * 1000 );

	return Temp;

}
static float32 LM35_u16ReadTempAsync(uint8 LM35_u8ChannelNum)
{
	uint16 LM35Value;
	float Temp = 0;

	ADC_voidStartConversion();
	LM35Value = ADC_u16ReadASync();

	Temp = ( (((float)LM35Value)/(1023.0*2)) * 1000 );

	return Temp;
}
