#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"

#include "SVAR.h"
#include "SVAR_cfg.h"
#include "SVAR_priv.h"

uint8 SVAR_u8ActiveVarient ;
void SVAR_voidInit(void )
{
	 DIO_enuReadPin(SVAR_PIN_CONNECTION,&SVAR_u8ActiveVarient);
}
uint8 SVAR_u8GetActiveVariant(void)
{
	return SVAR_u8ActiveVarient ;
}
