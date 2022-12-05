/*
 * CFile1.c
 *
 * Created: 11/25/2022 3:40:43 PM
 *  Author: Dell
 */ 
#include "timer.h"
#include <math.h>

float64_t  prescaler=256.0;

/*
*1-this function sets timer configuration
*2-choose mode of operation as normal mode,TCCRO register
*3-set timer starting value, TCNT0 register
*/
EN_timerError_t setTimerConfigs(void)
{
	//choose mode of operation as normal mode,TCCRO register
	TCCR0=0x00;
	//set timer starting value to zero, TCNT0 register
	TCNT0=0x00;
	return TIMER_OK;
}

/*
*-this function starts the timer and it take number of needed overflows, and the prescaler
*-set prescaler according to calculations, and TCCR0 register, timer will start count after this step
*/
EN_timerError_t startTimer(uint32 numOfOverflows,uint32 preScaler)
{
	overflowCounter=0;
	EN_timerError_t errorState=TIMER_OK;
	//set prescaler according to calculations, and TCCR0 register, timer will start count after this step
	if(preScaler==1)		{	TCCR0 |=(1<<0);				errorState=TIMER_STARTED;			}   //CS02(0),CS01(0),CS00(1) , clk/(no prescalling)
	else if(preScaler==8)	{	TCCR0 |=(1<<1);				errorState=TIMER_STARTED;			}	//CS02(0),CS01(1),CS00(0) , clk/8(from prescaler)
	else if(preScaler==64)	{	TCCR0 |=(1<<0)|(1<<1);		errorState=TIMER_STARTED;			}	//CS02(0),CS01(1),CS00(1) , clk/64(from prescaler)
	else if(preScaler==256)	{	TCCR0 |=(1<<2);				errorState=TIMER_STARTED;			}	//CS02(1),CS01(0),CS00(0) , clk/256(from prescaler)
	else if(preScaler==1024){	TCCR0 |=(1<<0)|(1<<2);		errorState=TIMER_STARTED;			}	//CS02(1),CS01(0),CS00(1) , clk/1024(from prescaler)
	else													errorState=TIMER_FAIL;
	while(overflowCounter<numOfOverflows)
	{
		//wait untill overflow flag to be set
		while((TIFR &(1<<0))==0);
		//clear overflow flag
		TIFR |=(1<<0);
		overflowCounter++;
	}
	//overflowCounter=0;
	//stopTimer();
	return errorState;
	
}

/*
*this function stops timer by setting TCCR0 to 0
*/
EN_timerError_t stopTimer(void)
{
	TCCR0=0x00;
	return TIMER_STOPED;
}
/*
*-this function take the time delay in seconds
*-calculate tick time , max delay time, and number of neEded overflows
*-according to prescaler start timer then stop it
*/
EN_timerError_t delay_s(float64_t T_delay_s)
{
	T_tick=prescaler/F_cpu;
	T_max_delay=T_tick*twoToPowerOfNumOfBits;//T_tick*(2^8)
	numOfOverflows=ceil(T_delay_s/T_max_delay);
	if(prescaler==1)
	{
		startTimer(numOfOverflows,1);
		stopTimer();
		return TIMER_OK;
	}
	else if(prescaler==8)
	{
		startTimer(numOfOverflows,8);
		stopTimer();
		return TIMER_OK;
	}
	else if(prescaler==64)
	{
		startTimer(numOfOverflows,64);
		stopTimer();
		return TIMER_OK;
	}
	else if(prescaler==256)
	{
		startTimer(numOfOverflows,256);
		stopTimer();
		return TIMER_OK;
	}
	else if(prescaler==1024)
	{
		startTimer(numOfOverflows,1024);
		stopTimer();
		return TIMER_OK;
	}
	else
	return TIMER_FAIL;
}