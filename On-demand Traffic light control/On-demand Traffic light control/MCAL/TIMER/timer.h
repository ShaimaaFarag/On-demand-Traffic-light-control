/*
 * timer.h
 *
 * Created: 11/25/2022 3:40:36 PM
 *  Author: Dell
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*#include "../../Helpers/STD_types.h"
#include "../../Helpers/Utilities.h"
#include "../../MCAL_Registers/Mem_map32.h"*/
#include "../DIO/dio.h"

//enumeration for timer errors
#define timerNumOfBit 8
#define twoToPowerOfNumOfBits (1<<(timerNumOfBit)) // 2^8=256
#define  F_cpu 1000000

float64_t T_tick;
float64_t T_max_delay;
uint32  numOfOverflows;
uint32 overflowCounter;

typedef enum EN_timerError_t
{
	TIMER_OK=1,
	TIMER_STARTED,
	TIMER_STOPED,
	TIMER_FAIL
}EN_timerError_t;


EN_timerError_t setTimerConfigs(void);
EN_timerError_t startTimer(uint32 numOfOverflows,uint32 preScaler);
EN_timerError_t stopTimer(void);
EN_timerError_t delay_s(float64_t T_delay_s);




#endif /* TIMER_H_ */