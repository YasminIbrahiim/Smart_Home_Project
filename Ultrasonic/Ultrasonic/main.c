#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/io.h>
#include "DIO.h"
#include "LCD.h"
#include "LED.h"
#include "avr/delay.h"

#define  F_CPU 1000000UL

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

	while(1)
	{
		HCSR04_voidTrigger();
		u16Width = ICU_u16PulseWidth();

		u16Distance=((u16Width*34600)/(F_CPU*2));

		if (u16Distance>=80)
		{
			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);
			LED_enuWriteValue (LED_u8NUM_0  , LED_u8OFF);
			LCD_enuWriteChar(LCD_u8NUM_0 ,'n');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'o');
			LCD_enuWriteChar(LCD_u8NUM_0 ,' ');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'o');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'b');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'j');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'e');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'c');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'t');
			_delay_ms(500);

		}
		else
		{
			LCD_enuWriteChar(LCD_u8NUM_0 ,'D');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'I');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'S');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'T');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'A');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'N');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'C');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'E');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'=');

			LCD_enuWriteChar(LCD_u8NUM_0 ,(u16Distance/10)+48);
			LCD_enuWriteChar(LCD_u8NUM_0 ,(u16Distance%10)+48);

			LCD_enuWriteChar(LCD_u8NUM_0 ,'c');
			LCD_enuWriteChar(LCD_u8NUM_0 ,'m');

			_delay_ms(500);

			LCD_enuWriteCmd(LCD_u8NUM_0,0x01);

			LED_enuWriteValue (LED_u8NUM_0 , LED_u8ON );
		}


	}


}
