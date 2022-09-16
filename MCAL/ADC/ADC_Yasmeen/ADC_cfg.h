#ifndef ADC_CFG_H
#define ADC_CFG_H

#define ADC_VOLTAGE_REFERENCE   AREF

#define ADC_ADJUSTMENT_MODE     ADC_LEFT

#define ADC_CHANNEL_NUM         ADC_CHANNEL_NUM_0

#define ADC_AUTO_TRIGGIR_MODE   AUTO_TRIGGIR_ENABLE

#if ADC_AUTO_TRIGGIR_MODE == AUTO_TRIGGIR_ENABLE

#define ADC_AUTO_TRIGGIR_SOURCE FREE_RUNNING_MODE

#endif 

#define ADC_PRESCALLER        DIVISION_ON_2

#endif