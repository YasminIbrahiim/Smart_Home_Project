#ifndef TEMP_H
#define TEMP_H

#include "Temp_cfg.h"


void Temp_vidInit(uint8 TempChannel);
void Temp_vidReadTemp(void);

void Temp_vidTempSystemTask(void);


#endif
