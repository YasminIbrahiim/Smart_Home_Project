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
#include "TIM0.h"
#include "TIM2.h"
#include "PWM.h"
#include "EXTINT2.h"



void ReceiveData(void);
void Garage_voidOpenDoor(void);
void Garage_voidCloseDoor(void);

int main(void)
{
	GIE_voidDisable();
	DIO_voidInit();
	TIM0_voidInit();
	TIM2_VoidInit();
	SPI_voidInit();
	EXTINT2_voidInit();
	EXTINT2_voidEnable();
	EXTINT2_voidSetCallBack(Garage_voidCloseDoor);
	SPI_voidSetInterruptState(SPI_INT_DISABLE);
	GIE_voidEnable();
	DIO_enuPullWrite(DIO_u8PIN_10 , DIO_u8ACTIVATE);
	ReceiveData();
	while(1);

}

void ReceiveData(void)
{
	uint8 u8Char ;
	u8Char =  SPI_u8DataRecieve_Sync();

	if(u8Char == 'b')
	{
		Garage_voidOpenDoor();
	}

}
void Garage_voidOpenDoor(void)
{

	PWM_VoidFreq_DutyCycleCtrl(50, 4);

}

void Garage_voidCloseDoor(void)
{
	PWM_VoidFreq_DutyCycleCtrl(50, 10);

}
