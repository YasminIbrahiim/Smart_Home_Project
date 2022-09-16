

#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H

#include "TIM0_cfg.h"



#define TIM0_NO_CLK_SRC                  0
#define TIM0_NO_PRESCALLER               1
#define TIM0_PRESCALLER_8                2
#define TIM0_PRESCALLER_64               3
#define TIM0_PRESCALLER_256              4
#define TIM0_PRESCALLER_1024             5
#define TIM0_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM0_EXT_CLK_SRC_RISING_EDGE     7

#define TCNT0     *((volatile uint8 *) 0x52 )
#define OCR0      *((volatile uint8 *) 0x5C )
#define TCCR0     *((volatile uint8 *) 0x53 )
#define TIMSK     *((volatile uint8 *) 0x59 )
#define TIFR      *((volatile uint8 *) 0x58 )

#endif 