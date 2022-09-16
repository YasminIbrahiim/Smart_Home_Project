

#ifndef TIM2_PRIV_H
#define TIM2_PRIV_H


#define  TIM2_NORMAL_MODE                0 
#define  TIM2_PWM_PHASE_CORRECT_MODE     1
#define  TIM2_CTC_MODE                   2
#define  TIM2_FAST_PWM_MODE              3


#define TIM2_NO_CLK_SRC                 0
#define TIM2_NO_PRESCALLER              1
#define TIM2_PRESCALLER_8               2
#define TIM2_PRESCALLER_32              3
#define TIM2_PRESCALLER_64              4
#define TIM2_PRESCALLER_128          	5
#define TIM2_PRESCALLER_256    			6
#define TIM2_PRESCALLER_1024  			7


#define TCNT2     *((volatile uint8 *) 0x44 )
#define OCR2      *((volatile uint8 *) 0x43 )
#define TCCR2     *((volatile uint8 *) 0x45 )
#define TIMSK     *((volatile uint8 *) 0x59 )
#define TIFR      *((volatile uint8 *) 0x58 )


#endif
