#ifndef  TIM2_H 
#define  TIM2_H


void TIM2_VoidInit(void);
void TIM2_VoidSetPreloadValue(uint8 u8PreloadValueCpy);
void TIM2_voidSetOutputCompareValue(uint8 u8LoadValueCpy);
void TIM2_VoidEnableOVFInterrupt(void);
void TIM2_VoidDisableOVFInterrupt(void);
void TIM2_VoidEnableCTCInterrupt(void);
void TIM2_VoidDisableCTCInterrupt(void);
void TIM2_VoidSetOVFCallback(pf pfOVFCallbackCpy);
void TIM2_VoidSetCTCCallback(pf pfCTCCallbackCpy);
void TIM2_VoidDelayMs(uint16 u16DelayTimeCpy);

#endif



