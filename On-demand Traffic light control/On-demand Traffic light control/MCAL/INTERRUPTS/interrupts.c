/*
 * interrupts.c
 *
 * Created: 11/25/2022 6:29:07 PM
 *  Author: Dell
 */ 
#include "interrupts.h"
/*
*-this function enable interrupt 0 at sense of rising edge
*/
void risingEdgeInterrupt(void)
{
	
	//enable global interrupts->seting bit 7 in status register to 1
	/*SET_BIT(SREG,7);
	CLEAR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
	SET_BIT(GICR,6);*/
	sei();
	//choose the external interrupts sense-sense rising edge
	MCUCR |=(1<<ISC00) |(1<<ISC01);
	//enable external interrupt 0
	GICR |=(1<<INT0);
}