#include "../../LIB/STD_Types.h"

#include "../SVAR/SVAR.h"

#include "ICUM.h"
#include "ICUM_cfg.h"
#include "ICUM_priv.h"



uint16  ovf = 0;
float32 Ton = 0;
float32 Tonu = 0;
float32 Ttotal = 0 ;
uint8 ICUM_u8FirstReading = 0 ;
uint8 ICUM_u8ActiveVariant ;


void ICUM_voidInit(void) 
{
	ICUM_u8ActiveVariant = SVAR_u8GetActiveVariant();
	ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfcallback(ICUM_voidExtIntISR);
    ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfOvfCallback(ICUM_voidOvfIsr);
    
}

void ICUM_voidGetFreqDuty(float32 * pf32FreqCpy , float32 *f32DutyCpy)
{
    *pf32FreqCpy	=
    		((float32)ICUM_apfConfigSet[ICUM_u8ActiveVariant].u32TimerFreq)
			/ (Ttotal);
    
	*f32DutyCpy  =  Tonu / Ttotal ;

}

void ICUM_voidExtIntISR(void)
{
	static uint8 ICUM_u8CntrReading = 1;
	
	if (ICUM_u8CntrReading == 1)
	{
		ICUM_u8FirstReading =
		ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfCntrValue();
		ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfChangesense(FALLING_EDGE);
		ovf = 0 ;
		ICUM_u8CntrReading  = 2 ;
	}
	else if (ICUM_u8CntrReading == 2)
	{
		Ton = 
		(float32)((ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfCntrValue()
		+(ovf*ICUM_apfConfigSet[ICUM_u8ActiveVariant].u16OvfCount))
		- ICUM_u8FirstReading );
		ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfChangesense(RISING_EDGE);
		
		ICUM_u8CntrReading  = 3 ;
	}
	else if (ICUM_u8CntrReading == 3)
	{
		Ttotal =(float32)(ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfCntrValue())
		+ (ovf*(ICUM_apfConfigSet[ICUM_u8ActiveVariant].u16OvfCount))
		- ICUM_u8FirstReading ;
		Tonu = Ton ;
		ovf = 0 ;
		ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfChangesense(FALLING_EDGE);
		ICUM_u8FirstReading =
		ICUM_apfConfigSet[ICUM_u8ActiveVariant].pfCntrValue();
		
		ICUM_u8CntrReading =2 ;
	}
	else 
	{
		
	}
	
	
	
	
	
	
	
	
}

void ICUM_voidOvfIsr(void)
{
	static uint8 ovfCnt = 0;
	ovfCnt++;
	ovf++;
}





