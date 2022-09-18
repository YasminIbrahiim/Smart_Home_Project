/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: iTECH
 */

#include <avr/delay.h>
#include "STD_Types.h"
#include "BIT_Math.h"
#include "DIO.h"
#include "GIE.h"
#include "SPI.h"
#include "LCD.h"
#include "KEYPAD_int.h"

uint8 Enter_Password(void);
void Check_Pass(void);

uint8 u8PASS[] = {"123456789"};
int main(void)
{
	GIE_voidDisable();
	DIO_voidInit();
	KEYPAD_voidInit();
	LCD_voidInit();
	SPI_voidInit();
	SPI_voidSetInterruptState(SPI_INT_DISABLE);

	Check_Pass();

	while(1)
	{

	}
}


uint8 Enter_Password(void)
{
	uint8 Temp = 0xFF;

	while(Temp == 0xFF)
	{
		Temp = KEYPAD_uint8GetPressedKey();
		_delay_ms(100);
	}

	return Temp;

}

void Check_Pass(void)
{
	uint8 au8EnterPass[]     = {"Enter Password"};
	uint8 au8CorrectPass[]   = {"   Correct"};
	uint8 au8IncorrectPass[] = {"   Incorrect"};
	uint8 au8WritePass[]     = {"   Password"};
	uint8 au8Password;
	uint8 u8CtrLOC;


	LCD_enuWriteString(LCD_u8NUM_0 , au8EnterPass ,14);
	_delay_ms(1000);

	for(u8CtrLOC = 0; u8CtrLOC < 9 ;u8CtrLOC++)
	{

		au8Password = Enter_Password();
		if(au8Password == '1')
		{
			DIO_enuWritePin(DIO_u8PIN_24 , DIO_u8HIGH);
		}
		if(u8PASS[0] == '1')
		{
			DIO_enuWritePin(DIO_u8PIN_25 , DIO_u8HIGH);
		}


		if(u8PASS[u8CtrLOC] == au8Password)
		{
			if(u8CtrLOC == 0)
			{
				LCD_enuWriteCmd(LCD_u8NUM_0 , LCD_u8CLEAR);
			}
			_delay_ms(100);
			LCD_enuWriteChar(LCD_u8NUM_0 , '*');
		}else
		{
			LCD_enuWriteCmd(LCD_u8NUM_0 , LCD_u8CLEAR);
			_delay_ms(100);
			LCD_enuWriteString(LCD_u8NUM_0 , au8IncorrectPass ,12 );

			LCD_enuWriteCmd(LCD_u8NUM_0 , 0xc0);
			LCD_enuWriteString(LCD_u8NUM_0 , au8WritePass ,11 );
			_delay_ms(1000);
			LCD_enuWriteCmd(LCD_u8NUM_0 , LCD_u8CLEAR);
			_delay_ms(1000);
			Check_Pass();
		}

	}
	if(u8CtrLOC == 9)
	{
		uint8 SendChar = 'b';
		LCD_enuWriteCmd(LCD_u8NUM_0 , LCD_u8CLEAR);
		_delay_ms(100);
		LCD_enuWriteString(LCD_u8NUM_0 , au8CorrectPass ,10);
		LCD_enuWriteCmd(LCD_u8NUM_0 , 0xc0);
		LCD_enuWriteString(LCD_u8NUM_0 , au8WritePass ,11 );

		SPI_u8DataTransfer_Sync(SendChar);
	}

}



