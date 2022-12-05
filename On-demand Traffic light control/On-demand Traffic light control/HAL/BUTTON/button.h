/*
 * button.h
 *
 * Created: 11/25/2022 8:52:26 PM
 *  Author: Dell
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPTS/interrupts.h"
#include "../../MCAL/TIMER/timer.h"

//interrupt 0 port and pin
#define INT0_BUTTON_PORT PORT_D
#define INT0_BUTTON_PIN  PIN2

void buttonInit(uint8_t pin, uint8_t port);
void buttonRead(uint8_t pin,uint8_t port, uint8_t *value);



#endif /* BUTTON_H_ */