
#ifndef LM35_H
#define LM35_H

#include "LM35_cfg.h"

void LM35_vidInit(uint8 LM35_u8ChannelNum);
float32 LM35_u16ReadTemp(uint8 LM35_u8ChannelNum);
void LM35_u16ReadTempUpdate(void);


#endif
