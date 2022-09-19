///*
// * 7_seg.c
// *
// *  Created on: Aug 24, 2022
// *      Author: Nourhan
// */
//#include "../../LIB/STD_Types.h"
//#include "../../LIB/BIT_MATH.h"
//
//#include "../../MCAL/DIO/DIO.h"
//#include "../../HAL/SEV/SEV.h"
//
//#include <util/delay.h>
//
//int sev_2()
//{
//	DIO_voidInit();
//	DIO_enuWritePin(DIO_u8PIN_29 , DIO_u8HIGH);
//
//	SEV_enuMode(SEV_u8NUM_1 , SEV_u8ON);
//
//	SEV_enuMode(SEV_u8NUM_0 , SEV_u8ON);
//	uint8 counterCpy0,counterCpy1 , PushButton_u8Value;
//
//	while(1)
//	{
//		for(counterCpy0 = 0 ; counterCpy0 < 10 ;counterCpy0++)
//		{
//			SEV_enuWrite(SEV_u8NUM_0 , counterCpy0);
//
//			for(counterCpy1 = 0 ; counterCpy1 < 10 ;counterCpy1++)
//			{
//				SEV_enuWrite(SEV_u8NUM_1 , counterCpy1);
//				_delay_ms(500);
//
//			}
//		}
//	}
//}
//
//
