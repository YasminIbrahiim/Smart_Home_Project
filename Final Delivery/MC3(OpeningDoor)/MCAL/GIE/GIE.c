#include "STD_Types.h"
#include "BIT_Math.h"

#include "GIE.h"
#include "GIE_cfg.h"
#include "GIE_priv.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}


