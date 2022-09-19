#ifndef TEMP_PRIV_H
#define TEMP_PRIV_H


#define TEMP_StateON			   0x44
#define TEMP_StateOFF			   0xEE


typedef struct
{
	uint8			u8TempState;
	uint8       	u8RELAYstrChannel;
	uint8		  	u8LM35strChannel;
	uint8		  	u8BuzzstrChannel;
	float32		 	u8TempNormal;
	float32		 	u8TempThreshold;
	float32		 	u8TempCurrent;
	tenuErrorStatus tenuLM35_ErrorState;
}tstrTempCfg;

extern tstrTempCfg Temp_astrChannelMapping[TEMP_MAX_NUM];



#endif
