/*
 * app.h
 *
 * Created: 11/25/2022 1:42:29 AM
 *  Author: Dell
 */ 


#ifndef APP_H_
#define APP_H_

//#include "../MCAL/DIO/dio.h"
#include "../HAL/BUTTON/button.h"
#include "../HAL/LED/led.h"
//#include "../MCAL/INTERRUPTS/interrupts.h"

typedef enum EN_trafficModes_t
{
	normalMode,
	pedestrianMode
}EN_trafficModes_t;

typedef enum EN_phase_t
{
	CARS_MOVE,   //cars green led is on and pedestrian red led is on
	CARS_WAIT,   //cars yellow led is blinking and pedestrian yellow led is blinking
	CARS_STOP	////cars red led is on and pedestrian green led is on
}EN_phase_t;

typedef enum EN_afterBlinkPhase_t
{
	GOTO_CARS_MOVE,   //cars green led is on and pedestrian red led is on
	GOTO_CARS_STOP	////cars red led is on and pedestrian green led is on
}EN_afterBlinkPhase_t;



void appStart(void);

void testINTERRUPT(void);



#endif /* APP_H_ */