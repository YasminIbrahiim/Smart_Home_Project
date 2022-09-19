/*
 * custom.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Nourhan
 */

#ifndef APP_CUSTOM_H_
#define APP_CUSTOM_H_
#include "../LIB/STD_Types.h"


void puin8_calculation(float32 *ptrResult);
float32 calc(uint8 f32Op1 , uint8 f32Op2 , uint8 u8OpType);

uint8 customCharN[8] = {
  0b00000000,
  0b00001000,
  0b00000010,
  0b00000010,
  0b00011110,
  0b00000000,
  0b00000000,
  0b00000000
};
uint8 customCharO[] = {
  0x00,
  0x00,
  0x0E,
  0x0A,
  0x0F,
  0x02,
  0x02,
  0x0E
};
uint8 customCharH[] = {
  0x0F,
  0x01,
  0x0F,
  0x0B,
  0x1F,
  0x00,
  0x00,
  0x00
};

uint8 customCharA[] = {
  0x08,
  0x08,
  0x08,
  0x08,
  0x0F,
  0x00,
  0x00,
  0x00
};

uint8 customCharNend[] = {
  0x00,
  0x00,
  0x04,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x00
};

uint8 customCharR[] = {
  0x00,
  0x00,
  0x00,
  0x01,
  0x01,
  0x02,
  0x06,
  0x18
};
#endif /* APP_CUSTOM_H_ */
