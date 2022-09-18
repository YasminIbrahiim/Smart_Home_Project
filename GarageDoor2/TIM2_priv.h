#ifndef  TIM2_PRIV_H
#define  TIM2_PRIV_H

#define TIMSK *((volatile uint8*)0x59)
#define TIFR  *((volatile uint8*)0x58)
#define SFIOR *((volatile uint8*)0x50)
#define TCCR2 *((volatile uint8*)0x45)
#define TCNT2 *((volatile uint8*)0x44)
#define OCR2  *((volatile uint8*)0x43)
#define ASSR  *((volatile uint8*)0x42)

#define TIM2_NORMAL_MODE                   0
#define TIM2_PWM_PHASE_CORRECT_MODE        1
#define TIM2_CTC_MODE                      2     
#define TIM2_FAST_PWM_MODE                 3 

#define TIM2_NO_CLK_SOURCE                 0 
#define TIM2_NO_PRESCALER                  1
#define TIM2_PRESCALER_8                   2
#define TIM2_PRESCALER_32                  3
#define TIM2_PRESCALER_64                  4
#define TIM2_PRESCALER_128                 5
#define TIM2_PRESCALER_256                 6
#define TIM2_PRESCALER_1024                7

#define ASYNC_MODE   0
#define SYNC_MODE    1

#define CPU_FREQ 8000000
  

#endif



