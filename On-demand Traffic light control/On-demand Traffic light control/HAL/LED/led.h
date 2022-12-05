/*
 * led.h
 *
 * Created: 11/25/2022 7:46:15 PM
 *  Author: Dell
 */ 


#ifndef LED_H_
#define LED_H_


#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/INTERRUPTS/interrupts.h"
#include "../../MCAL/TIMER/timer.h"

//car leds port
#define carRed_led_port		PORT_C
#define carYellow_led_port  PORT_C
#define carGreen_led_port   PORT_C
//car leds pins
#define carRed_led_pin      PIN0
#define carYellow_led_pin   PIN1
#define carGreen_led_pin    PIN2
///////////////////////////////////////
//pedestrians leds port
#define pedestriansRed_led_port		PORT_A
#define pedestriansYellow_led_port  PORT_A
#define pedestriansGreen_led_port   PORT_A
//pedestrians leds pins
#define pedestriansRed_led_pin      PIN0
#define pedestriansYellow_led_pin   PIN1
#define pedestriansGreen_led_pin    PIN2


void LED_init(uint8_t led_Pin , uint8_t led_Port);
void LED_on(uint8_t led_Pin , uint8_t led_Port);
void LED_off(uint8_t led_Pin , uint8_t led_Port);
void LED_toggle(uint8_t led_Pin , uint8_t led_Port );
void LEDs_init(void);
void LEDs_off(void);
void LEDs_yellowBlink(void);



#endif /* LED_H_ */