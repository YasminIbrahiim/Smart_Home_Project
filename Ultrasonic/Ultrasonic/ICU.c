#include "STD_Types.h"
#include "BIT_Math.h"
#include <avr/io.h>
#include "ICU.h"
#include "ICU_priv.h"


uint16 u16High, u16Start, u16End;

uint16 ICU_u16PulseWidth(void)
{
	TCCR1A = 0;
    SET_BIT(TIFR,5);  	/* Clear ICF (Input Capture flag)  */

 	/* Rising edge, no prescaler , noise canceler*/
    SET_BIT(TCCR1B,0);
    SET_BIT(TCCR1B,6);
    SET_BIT(TCCR1B,7);

    while (GET_BIT(TIFR,5) == 0);
    u16Start = ICR1;  		/* Take value of capture register */
    SET_BIT(TIFR,5);   	/* Clear ICF flag */

 	/* Falling edge, no prescaler ,noise canceler*/
    SET_BIT(TCCR1B,0);
    CLR_BIT(TCCR1B,6);
    SET_BIT(TCCR1B,7);

    while (GET_BIT(TIFR,5) == 0);
    u16End = ICR1;  		/* Take value of capture register */
    SET_BIT(TIFR,5);  	/* Clear ICF flag */
	TCNT1=0;
    TCCR1B = 0;  		/* Stop the timer */
	u16High=u16End-u16Start;

	return u16High;
}

