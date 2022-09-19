/*
 * calc.c
 *
 *  Created on: Aug 28, 2022
 *      Author: Nourhan
 */

#include <util/delay.h>
#include "../LIB/STD_Types.h"
#include "../LIB/BIT_Math.h"

#include "../MCAL/DIO/DIO.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/KEYPAD/KEYPAD_int.h"


float32 calc(uint8 f32Op1 , uint8 f32Op2 , uint8 u8OpType)
{
	float32 result;
	switch(u8OpType)
	{
	case '+':
		result = f32Op1 + f32Op2;
	break;

	case '-':
		result = f32Op1 - f32Op2;
	break;

	case '*':
		result = f32Op1 * f32Op2;

	break;

	case '/':
		result = (float32)f32Op1 / f32Op2;
	break;
	}

	return result;
}



void puin8_calculation(float32 *ptrResult)
{
	float32 pas8KeyPadChar[2] = {0.0} ;
	uint8 u8SizeCpy = 0;
	uint8 u8CntrLoc = 0;
	uint8 u8FlagOp = 0;
	uint8 u8FlagFloat = 0;
	uint8 u8CntrFloat = 0;
	uint8 u8OpType = 0;
	uint8 u8KeyPadChar = 0;
	float32 s8Number = 0.0;
	*ptrResult = 7;

	while(u8KeyPadChar != '=')
	{
		u8CntrLoc++;

		u8KeyPadChar = 	KEYPAD_uint8GetPressedKey();

		while(u8KeyPadChar == 0xff){
			u8KeyPadChar = 	KEYPAD_uint8GetPressedKey();
		}

		switch(u8KeyPadChar)
		{
		case '+' :
			 pas8KeyPadChar[0] = s8Number ;
			u8SizeCpy++;
			u8OpType = '+';
			u8FlagOp = 0;

		break;

		case '-' :
			 pas8KeyPadChar[0] = s8Number ;
			u8OpType = '-';
			u8SizeCpy++;
			u8FlagOp = 0;



		break;

		case '/' :
			 pas8KeyPadChar[0] = s8Number ;
			u8OpType = '/';
			u8SizeCpy++;
			u8FlagOp = 0;


		break;

		case '*' :
			pas8KeyPadChar[0] = s8Number ;
			u8OpType = '*';
			u8SizeCpy++;
			u8FlagOp = 0;



		break;

		case '.' :
			u8FlagFloat = 1;
		break;

		case '=' :
			 pas8KeyPadChar[1] = s8Number ;
			u8SizeCpy++;
			*ptrResult = calc(pas8KeyPadChar[0] , pas8KeyPadChar[1],u8OpType );


		break;

		default:

			if(u8FlagOp == 1)
			{

				s8Number = s8Number*10 + (u8KeyPadChar - '0');
			}
			else{
				s8Number = (u8KeyPadChar - '0');
				u8FlagOp = 1;
			}

		break;
		}


		LCD_enuWriteChar(LCD_u8NUM_0,u8KeyPadChar);
		_delay_ms(200);
	}

}


