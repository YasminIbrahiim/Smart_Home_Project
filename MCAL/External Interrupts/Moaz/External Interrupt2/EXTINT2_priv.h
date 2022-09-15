
#ifndef EXTINT2_PRIV_H
#define EXTINT2_PRIV_H


#define FALLING_EDGE	10
#define RISING_EDGE		15

#define GIFR        	*((volatile uint8 * )0x5A)
#define GICR        	*((volatile uint8 * )0x5B)
#define MCUCSR       	*((volatile uint8 * )0x54)

#endif
