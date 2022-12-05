/*
 * button.c
 *
 * Created: 11/25/2022 8:52:08 PM
 *  Author: Dell
 */ 

#include "button.h"

/*
*-this function initialize button pin as input pin using dio_init function
*/
void buttonInit(uint8_t pin, uint8_t port)
{
	DIO_init(pin,port,INPUT);
}

/*
*-this function read the value of button pin using dio_read function
*/
void buttonRead(uint8_t pin,uint8_t port, uint8_t *value)
{
	DIO_read(pin, port, value);
}