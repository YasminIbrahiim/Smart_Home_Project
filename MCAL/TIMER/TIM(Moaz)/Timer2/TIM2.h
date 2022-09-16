
#ifndef TIM2_h
#define TIM2_h
void TIM2_voidInit(void);
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM2_voidEnableOVFIntterrupt(void);
void TIM2_voidDisableOVFIntterrupt(void);
void TIM2_voidEnableCTCIntterrupt(void);
void TIM2_voidDisableCTCIntterrupt(void);
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy);
void TIM2_voidDelayMs(uint16 u16DalayTimeCpy);
uint16 TIM2_u16GetCntrValue(void);

#endif