/*
 * main.c
 *
 *  Created on: Aug 31, 2022
 *      Author: nourhan
 */
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/GIE/GIE.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/ADC/ADC.h"


#include "../HAL/LED/LED.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/LM35/LM35.h"
#include "../HAL/RELAY/RELAY.h"

#include "Temp/Temp.h"

#include <util/delay.h>

int main()
{
//	uint16 temp;
//	DIO_voidInit();
//	ADC_voidEnable();
//	ADC_voidInit();
//	ADC_voidEnable();
//	LCD_voidInit();
//	DIO_enuPullWrite(DIO_u8PIN_0,DIO_u8HIGH);
	Temp_vidInit(0);

	while(1)
	{
		Temp_vidReadTemp();
//		Relay_enuState(0 , RELAY_ON);
		Temp_vidTempSystemTask();

//		ADC_voidStartConversion();
//
//		temp = ADC_u16ReadSync();
//
////		LM35_u16ReadTemp(LM35_CHANNEL_NUM_0);
//		LCD_enuWriteCmd(LCD_u8NUM_1, LCD_u8CLEAR);
//		LCD_enuWriteChar(LCD_u8NUM_1 , ' ');
//		LCD_enuWritenumber(LCD_u8NUM_1 , temp);
		_delay_ms(500);



	}

	return 0;

}



