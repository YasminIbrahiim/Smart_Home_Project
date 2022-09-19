#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "LED.h"
#include "I2C.h"
#include "avr/delay.h"

#define  F_CPU 8000000UL

uint16 u16Distance, u16Width;

void HCSR04_voidTrigger(void)
{
	DIO_enuWritePin(DIO_u8PIN_31 , DIO_u8HIGH);
	_delay_ms(15);
	DIO_enuWritePin(DIO_u8PIN_31 , DIO_u8LOW);
}

void main()
{
	DIO_voidInit();
	LCD_voidInit();
	I2C_voidInit();
	uint8 u8BoolMessageSent = 0x00;


	while(1)
	{
		HCSR04_voidTrigger();
		u16Width = ICU_u16PulseWidth();
		u16Distance=((u16Width*34600)/(F_CPU*2));
		if (u16Distance>=80 )
		{
			_delay_ms(500);
			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);
			_delay_ms(500);
			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);
			LED_enuWriteValue (LED_u8NUM_0  , LED_u8OFF);
			LCD_enuWriteData(LCD_u8NUM_0, "Move Closer!");


		}
		else if(u16Distance < 80 && u16Distance > 40)
		{
			_delay_ms(500);
			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);
			_delay_ms(500);
			LCD_RowCol_Select(LCD_u8NUM_0,0,1);
			LCD_enuWriteData(LCD_u8NUM_0, "Distance = ");
			LCD_enuWriteChar(LCD_u8NUM_0 ,(u16Distance/10)+48);
			LCD_enuWriteChar(LCD_u8NUM_0 ,(u16Distance%10)+48);
			LCD_enuWriteData(LCD_u8NUM_0, "CM");
			LCD_RowCol_Select(LCD_u8NUM_0,1,1);
			LCD_enuWriteData(LCD_u8NUM_0, "Enter Password! ");
			LED_enuWriteValue (LED_u8NUM_0 , LED_u8ON );
			if(u8BoolMessageSent == 0x00)
			{
				I2C_voidMasterTransmit(0x09,"CA",2);
				u8BoolMessageSent = 0x01;
			}

		}
		else
		{
			_delay_ms(500);
			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);
			_delay_ms(500);
			LCD_RowCol_Select(LCD_u8NUM_0,0,1);
			LCD_enuWriteData(LCD_u8NUM_0, "Can't Open Door!");
			LCD_RowCol_Select(LCD_u8NUM_0,1,1);
			LCD_enuWriteData(LCD_u8NUM_0, "Move Further! ");
		}

	}


}
