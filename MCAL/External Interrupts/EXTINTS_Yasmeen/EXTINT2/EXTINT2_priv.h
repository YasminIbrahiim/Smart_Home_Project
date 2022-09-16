/*****************************************************/

#ifndef  EXTINT2_PRIV_H
#define  EXTINT2_PRIV_H


#define FALLING_EDGE     11
#define RISING_EDGE      4

#define GICR     *((volatile uint8*)0x5B)
#define MCUCSR   *((volatile uint8*)0x54)
#define GIFR	 *((volatile uint8*)0x5A)


#endif
