#ifndef LM35_PRIV_H
#define LM35_PRIV_H


#define LM35_ReadSynch  	0x66
#define LM35_ReadAsynch  	0xCC


typedef struct
{
	uint8 u8ADCChannelMap;
	uint8 u8ReadMode;
	float32 f32ChannelValue;
	tenuErrorStatus tenuLM35_ErrorState;
}tstrLM35Cfg;

extern tstrLM35Cfg LM35_astrChannelMapping[LM35_MAX_NUM];



#endif
