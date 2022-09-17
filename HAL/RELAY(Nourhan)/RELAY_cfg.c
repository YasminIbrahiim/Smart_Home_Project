#include "../../LIB/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "RELAY_cfg.h"
#include "RELAY_priv.h"


tstrRelayCfg Relay_astrPinMapping[RELAY_MAX_NUM]={

	{ Relay_intSupply, Relay_ACNO ,.u8DioPinCfg.u8inpSupply = { DIO_u8PIN_4  ,DIO_u8PIN_6 } } ,
	{ Relay_extSupply, Relay_ACNC ,.u8DioPinCfg.u8extSupply =  {Relay_u8extHIGH ,DIO_u8PIN_5}  }

};
