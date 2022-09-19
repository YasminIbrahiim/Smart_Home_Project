#ifndef TIM0_PRIV_H
#define TIM0_PRIV_H

#define  TIM0_NORMAL_MODE                0 
#define  TIM0_PWM_PHASE_CORRECT_MODE     1
#define  TIM0_CTC_MODE                   2
#define  TIM0_FAST_PWM_MODE              3

#define  TIM0_Non_PWM_OFF	             0
#define  TIM0_Non_PWM_TGL   	         1
#define  TIM0_Non_PWM_CLR       	     2
#define  TIM0_Non_PWM_Set           	 3
#define  TIM0_Fast_PWM_CLR               4
#define  TIM0_Fast_PWM_SET               5
#define  TIM0_PHC_PWM_CLR_UPCNT          6
#define  TIM0_PHC_PWM_SET_UPCNT          7


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
