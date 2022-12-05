/*
 * led.c
 *
 * Created: 11/25/2022 7:46:27 PM
 *  Author: Dell
 */ 
#include "led.h"
/*
*-this function initialize the pin of led as an output pin usind dio_init function
*/
void LED_init(uint8_t led_Pin , uint8_t led_Port)
{
	DIO_init(led_Pin,led_Port,OUTPUT);
}

/*
*--this function turning led pin on by writing 1 on this pin using dio_write function
*/
void LED_on(uint8_t led_Pin , uint8_t led_Port)
{
	DIO_write(led_Pin,led_Port,HIGH);
}

/*
*--this function turning led pin off by writing 0 on this pin using dio_write function
*/
void LED_off(uint8_t led_Pin , uint8_t led_Port)
{
	DIO_write(led_Pin,led_Port,LOW);
}

/*
*--this function toggling led pin using dio_toggle function
*/
void LED_toggle(uint8_t led_Pin , uint8_t led_Port )
{
	DIO_toggle(led_Pin,led_Port);
}
/*
*-this function initialize all led using led_init function
*/
/*void LEDs_init(void)
{
	//initialize car leds
	LED_init(carRed_led_pin,carRed_led_port);
	LED_init(carYellow_led_pin,carYellow_led_port);
	LED_init(carGreen_led_pin,carGreen_led_port);
	//initialize pedestrians leds
	LED_init(pedestriansRed_led_pin,pedestriansRed_led_port);
	LED_init(pedestriansYellow_led_pin,pedestriansYellow_led_port);
	LED_init(pedestriansGreen_led_pin,pedestriansGreen_led_port);
}*/

/*
* this function turn off all leds
*/
/*void LEDs_off(void)
{
	//turn off car leds
	LED_off(carRed_led_pin,carRed_led_port);
	LED_off(carYellow_led_pin,carYellow_led_port);
	LED_off(carGreen_led_pin,carGreen_led_port);
	//turn off pedestrians leds
	LED_off(pedestriansRed_led_pin,pedestriansRed_led_port);
	LED_off(pedestriansYellow_led_pin,pedestriansYellow_led_port);
	LED_off(pedestriansGreen_led_pin,pedestriansGreen_led_port);
}*/

/*
*-this function blink the yellow leds for 5 seconds and it toggles every 500ms(0.5s)
*/
/*void LEDs_yellowBlink(void)
{
	for(uint8_t counter = 0 ; counter < 10 ; counter++)
	{
		
		LED_toggle(carYellow_led_pin,carYellow_led_port);
		LED_toggle(pedestriansYellow_led_pin,pedestriansYellow_led_port);
		delay_s(0.5);
	}
}*/