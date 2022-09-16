

#ifndef TIM0_H
#define TIM0_H

#include "TIM0_cfg.h"

#define  TIM0_NORMAL_MODE                0 
#define  TIM0_PWM_PHASE_CORRECT_MODE     1
#define  TIM0_CTC_MODE                   2
#define  TIM0_FAST_PWM_MODE              3

void TIM0_voidInit(void);
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM0_voidEnableOVFIntterrupt(void);
void TIM0_voidDisableOVFIntterrupt(void);
void TIM0_voidEnableCTCIntterrupt(void);
void TIM0_voidDisableCTCIntterrupt(void);
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy);
void TIM0_voidDelayMs(uint16 u16DalayTimeCpy);


uint16 TIM0_u16GetCntrValue(void);

#endif