/*
 * dio.h
 *
 * Created: 11/24/2022 11:44:58 PM
 *  Author: Dell
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Helpers/STD_types.h"
#include "../../Helpers/Utilities.h"
#include "../../MCAL_Registers/Mem_map32.h"
//#include "../TIMER/timer.h"

//port defines
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//direction defines
#define INPUT  0
#define OUTPUT 1

//values defines
#define DIO_HIGH 1
#define DIO_LOW  0

//port direction defines
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xFF

//port values defines
#define PORT_LOW  0x00
#define PORT_HIGH 0xFF

#define MAX_PINS 7

//pin defines
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
/////////////////
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//enumeration for dio errors
typedef enum EN_dioError_t
{
	DIO_OK=1,
	 DIO_FAIL
}EN_dioError_t;


EN_dioError_t DIO_init (uint8_t pin, uint8_t port, uint8_t direction);
EN_dioError_t DIO_write (uint8_t pin, uint8_t port, uint8_t value);
EN_dioError_t DIO_toggle (uint8_t pin, uint8_t port);
EN_dioError_t DIO_read(uint8_t pin, uint8_t port, uint8_t *value);
#endif /* DIO_H_ */