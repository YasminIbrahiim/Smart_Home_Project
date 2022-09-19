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
	Temp_vidInit(0);

	while(1)
	{
		Temp_vidReadTemp();
		Temp_vidTempSystemTask();
		_delay_ms(100);


	}

	return 0;

}



