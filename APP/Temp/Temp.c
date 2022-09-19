#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/TIM/TIM0/TIM0.h"
#include "../../MCAL/GIE/GIE.h"

#include "../../HAL/LM35/LM35.h"
#include "../../HAL/RELAY/RELAY.h"
#include "../../HAL/LCD/LCD.h"
#include "../../HAL/LED/LED.h"

#include "Temp.h"
#include "Temp_cfg.h"
#include "Temp_priv.h"


uint8 Temp_u8Channel;

void BuzzerON(void)
{

	LED_enuToggle(LED_u8NUM_0);
	TIM0_voidDelayMs(3000);

}
void BuzzerOFF(void)
{
	LED_enuWriteValue(Temp_astrChannelMapping[Temp_u8Channel].u8BuzzstrChannel , LED_u8OFF);

}

void buzzerInit(void)
{
	GIE_voidDisable();
	TIM0_voidFPWMInit();
	TIM0_voidSetCtcCallback(BuzzerON);
	TIM0_voidEnableCTCIntterrupt();
	GIE_voidEnable();
}
void Temp_vidInit(uint8 TempChannel)
{

	LM35_vidInit(TempChannel);
	Temp_u8Channel = TempChannel;

}

void Temp_vidReadTemp(void)
{
	Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent =
			LM35_u16ReadTemp(Temp_astrChannelMapping[Temp_u8Channel].u8LM35strChannel);

	LCD_enuWriteCmd(LCD_u8NUM_1 , LCD_u8CLEAR);
	LCD_enuWriteChar(LCD_u8NUM_1 , ' ');
	LCD_enuWritenumber(LCD_u8NUM_1,Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent );
}


void Temp_vidTempSystemTask(void)
{

	Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent =
			LM35_u16ReadTemp(Temp_astrChannelMapping[Temp_u8Channel].u8LM35strChannel);
	if(Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent > TempFire)
	{
		buzzerInit();
	}
	else if(Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent < TempSafety)
	{
		BuzzerOFF();
	}

	switch(Temp_astrChannelMapping[Temp_u8Channel].u8TempState)
	{
	case TEMP_StateOFF:
	{
		if(Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent <
		(Temp_astrChannelMapping[Temp_u8Channel].u8TempNormal - Temp_astrChannelMapping[Temp_u8Channel].u8TempThreshold ))
		{
			Temp_astrChannelMapping[Temp_u8Channel].u8TempState = TEMP_StateON;
			Relay_enuState(Temp_astrChannelMapping[Temp_u8Channel].u8RELAYstrChannel , RELAY_ON);
		}

	}
	break;
	case TEMP_StateON:
	{
		if(Temp_astrChannelMapping[Temp_u8Channel].u8TempCurrent >
		(Temp_astrChannelMapping[Temp_u8Channel].u8TempNormal + Temp_astrChannelMapping[Temp_u8Channel].u8TempThreshold ))
		{
			Temp_astrChannelMapping[Temp_u8Channel].u8TempState = TEMP_StateOFF;
			Relay_enuState(Temp_astrChannelMapping[Temp_u8Channel].u8RELAYstrChannel , RELAY_OFF);
		}

	}
	break;

	}


}
