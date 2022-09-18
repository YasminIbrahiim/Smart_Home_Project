/******************************************************/
/* Author  : Ahmed Atia Atia                          */
/* Date    : 18 FEB 2018                              */
/* Version : 1V                                       */
/******************************************************/

/*             Liberary Directives                */
#include "STD_Types.h"
#include "Bit_Math.h"

/*             DIO Directives                     */
#include "DIO.h"
/*   KEYPAD */
#include "KEYPAD_int.h"
#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"

void KEYPAD_voidInit()
{
	/** activate pull up resistor column / inputs 	  */
	DIO_enuWritePin(KEYPAD_U8_COLUMN_1 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_COLUMN_2 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_COLUMN_3 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_COLUMN_4 ,DIO_u8HIGH );

	/** OUTPUT		 1	  */
	DIO_enuWritePin(KEYPAD_U8_ROW_1 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_ROW_2 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_ROW_3 ,DIO_u8HIGH );
	DIO_enuWritePin(KEYPAD_U8_ROW_4 ,DIO_u8HIGH );

}

uint8 KEYPAD_uint8GetPressedKey(void)
{
	uint8 u8one,u8two,u8three,u8four;
	uint8 LOC_uint8preesed = 0XFF;
	uint8 LOC_uint8ColumnValue ;
	/**   !comment : send row sequence  1  */

	DIO_enuWritePin(KEYPAD_U8_ROW_1,DIO_u8HIGH);
	DIO_enuWritePin(KEYPAD_U8_ROW_2,DIO_u8HIGH);
	DIO_enuWritePin(KEYPAD_U8_ROW_3,DIO_u8LOW);
	DIO_enuWritePin(KEYPAD_U8_ROW_4,DIO_u8HIGH);

	/**   !comment : Read columns  */
	DIO_enuReadPin(KEYPAD_U8_COLUMN_1,&u8one );
	DIO_enuReadPin(KEYPAD_U8_COLUMN_2,&u8two);
	DIO_enuReadPin(KEYPAD_U8_COLUMN_3,&u8three);
	DIO_enuReadPin(KEYPAD_U8_COLUMN_4,&u8four);


	LOC_uint8ColumnValue  = u8one | u8two << 1 | u8three <<2 | u8four<<3;




	switch(LOC_uint8ColumnValue)
	{
	case 0b00001110: LOC_uint8preesed = '1' ;
	break;

	case 0b00001101: LOC_uint8preesed = '2' ;
	break;

	case 0b00001011: LOC_uint8preesed = '3' ;
	break;

	case 0b00000111: LOC_uint8preesed = '-' ;
	break;

	default : LOC_uint8preesed = 0XFF ;
	}

	if(LOC_uint8preesed == 0XFF)
	{
		/**   !comment : send row sequence  2  */

		DIO_enuWritePin(KEYPAD_U8_ROW_1,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_2,DIO_u8LOW);
		DIO_enuWritePin(KEYPAD_U8_ROW_3,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_4,DIO_u8HIGH);

		/**   !comment : Read columns  */

		DIO_enuReadPin(KEYPAD_U8_COLUMN_1,&u8one );
		DIO_enuReadPin(KEYPAD_U8_COLUMN_2,&u8two);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_3,&u8three);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_4,&u8four);


		LOC_uint8ColumnValue  = u8one | u8two << 1 | u8three <<2 | u8four<<3;

		switch(LOC_uint8ColumnValue)
		{
		case 0b00001110: LOC_uint8preesed = '4' ;
		break;

		case 0b00001101: LOC_uint8preesed = '5' ;
		break;

		case 0b00001011: LOC_uint8preesed = '6' ;
		break;

		case 0b00000111: LOC_uint8preesed = '*' ;
		break;

		default : LOC_uint8preesed = 0XFF ;
		}
	}
	if(LOC_uint8preesed == 0XFF)
	{
		/**   !comment : send row sequence  3  */

		DIO_enuWritePin(KEYPAD_U8_ROW_1,DIO_u8LOW);
		DIO_enuWritePin(KEYPAD_U8_ROW_2,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_3,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_4,DIO_u8HIGH);

		/**   !comment : Read columns  */
		DIO_enuReadPin(KEYPAD_U8_COLUMN_1,&u8one );
		DIO_enuReadPin(KEYPAD_U8_COLUMN_2,&u8two);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_3,&u8three);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_4,&u8four);


		LOC_uint8ColumnValue  = u8one | u8two << 1 | u8three <<2 | u8four<<3;

		switch(LOC_uint8ColumnValue)
		{
		case 0b00001110: LOC_uint8preesed = '7' ;
		break;

		case 0b00001101: LOC_uint8preesed = '8' ;
		break;

		case 0b00001011: LOC_uint8preesed = '9' ;
		break;

		case 0b00000111: LOC_uint8preesed = '/' ;
		break;

		default : LOC_uint8preesed = 0XFF ;
		}
	}
	if(LOC_uint8preesed == 0XFF)
	{

		/**   !comment : send row sequence  4  */

		DIO_enuWritePin(KEYPAD_U8_ROW_1,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_2,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_3,DIO_u8HIGH);
		DIO_enuWritePin(KEYPAD_U8_ROW_4,DIO_u8LOW);

		/**   !comment : Read columns  */

		DIO_enuReadPin(KEYPAD_U8_COLUMN_1,&u8one );
		DIO_enuReadPin(KEYPAD_U8_COLUMN_2,&u8two);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_3,&u8three);
		DIO_enuReadPin(KEYPAD_U8_COLUMN_4,&u8four);


		LOC_uint8ColumnValue  = u8one | u8two << 1 | u8three <<2 | u8four<<3;

		switch(LOC_uint8ColumnValue)
		{
		case 0b00001110: LOC_uint8preesed = '.' ;
		break;

		case 0b00001101: LOC_uint8preesed = '0' ;
		break;

		case 0b00001011: LOC_uint8preesed = '=' ;
		break;

		case 0b00000111: LOC_uint8preesed = '+' ;
		break;

		default : LOC_uint8preesed = 0xff ;
		}
	}

	return LOC_uint8preesed ;
}
