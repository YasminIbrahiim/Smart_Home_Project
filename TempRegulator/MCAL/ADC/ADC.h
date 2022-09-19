#ifndef ADC_H
#define ADC_H

#include "ADC_cfg.h"

void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
void ADC_voidInterruptEnable(void);
void ADC_voidInterruptDisable(void);
void ADC_voidSetCallback(pf pfCallbackCpy);
uint16 ADC_u16ReadSync(void);
void ADC_voidStartConversion(void);
uint16 ADC_u16ReadASync(void);
float32 ADC_f32NumtoVolt(uint16 u16ReadCpy);

#endif
