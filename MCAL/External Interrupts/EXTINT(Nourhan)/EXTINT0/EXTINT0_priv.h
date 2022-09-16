

#ifndef EXTINT0_PRIV_H
#define EXTINT0_PRIV_H

#define LOW_LEVEL        0
#define IOC              5
#define FALLING_EDGE     10
#define RISING_EDGE      15


#define GIFR        *((volatile uint8 * )0x5A)
#define GICR        *((volatile uint8 * )0x5B)
#define MCUCR       *((volatile uint8 * )0x55)


#endif 






