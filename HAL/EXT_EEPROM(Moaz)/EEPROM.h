/*
 * EEPROM.h
 *
 *  Created on: Sep 18, 2022
 *      Author: Moaz
 */

#ifndef EEPROM_H_
#define EEPROM_H_

void EEPROM_voidWrite(uint8 u8AddressCpy , uint8 u8DataCpy, uint8 *u8BoolWritten);

void EEPROM_voidRead(uint8 u8AddressCpy, uint8 *u8DataCpy);


#endif
