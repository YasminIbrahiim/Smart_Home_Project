/*****************************************************/

#ifndef  EXTINT1_PRIV_H
#define  EXTINT1_PRIV_H

#define LOW_LEVEL        (2)
#define LOC              (3)
#define FALLING_EDGE     (5)
#define RISING_EDGE      (10)

#define GICR     *((volatile uint8*)0x5B)
#define MCUCR    *((volatile uint8*)0x55)
#define GIFR	 *((volatile uint8*)0x5A)


#endif
