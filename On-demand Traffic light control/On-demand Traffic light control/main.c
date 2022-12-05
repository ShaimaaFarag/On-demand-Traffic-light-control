/*
 * On-demand Traffic light control.c
 *
 * Created: 11/22/2022 11:38:33 PM
 * Author : Dell
 */ 

//#include <avr/io.h>
#include "APPLICATION/app.h"
/*#include "MCAL/DIO/dio.h"
#include "HAL/LED/led.h"
#include "HAL/BUTTON/button.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/INTERRUPTS/interrupts.h"*/

//#define  F_CPU 1000000
//#include <util/delay.h>

/*#define PIN1_PORT PORT_A
#define PIN1_PIN  PIN1
#define PIN2_PORT PORT_A
#define PIN2_PIN  PIN7

#define BUTTON1_PORT PORT_D
#define BUTTON1_PIN  PIN2

EN_dioError_t errorState;
void testDIO(void);
void testLED(void);
void tesBUTTON(void);
void testTIMER(void);
void testINTERRUPT(void);
*/
int main(void)
{
	
	appStart();
	/*//1-test dio driver
	testDIO();
	*/
	//2-test led driver
	//testLED();
	//3-test button driver
	//tesBUTTON();
	//4- test timer driver
	//testTIMER();
	//5-test intettupt driver
	//testINTERRUPT();

}
/*void testDIO()
{
	 errorState=DIO_init(4,PORT_A,OUTPUT);
	 errorState=DIO_init(1,PORT_B,INPUT);
	 errorState=DIO_init(0, PORT_B, OUTPUT);
	 uint8_t value;
	 DIO_read(1,PORT_B,&value);

	 while (1)
	 {
		 
		 DIO_write(4, PORT_A, HIGH);
		 DIO_write(0, PORT_B, LOW);
		 _delay_ms(1000);
		 DIO_write(4, PORT_A, LOW);
		 DIO_write(0, PORT_B, HIGH);
		 _delay_ms(1000);
		 
	 }
}
void testLED()
{
	LED_init(PIN1_PIN,PIN1_PORT);
	LED_init(PIN2_PIN,PIN2_PORT);
	LED_on(PIN1_PIN,PIN1_PORT);
	LED_off(PIN2_PIN,PIN2_PORT);
	while(1)
	{
		
		LED_toggle(PIN2_PIN,PIN2_PORT);
		LED_toggle(PIN1_PIN,PIN1_PORT);
		_delay_ms(1000);
	}
}
void tesBUTTON()
{
	uint8_t button_1_state;
	buttonInit(BUTTON1_PIN, BUTTON1_PORT);
	LED_init(PIN1_PIN,PIN1_PORT);
	LED_init(PIN2_PIN,PIN2_PORT);
	while(1)
	{
		
	buttonRead(BUTTON1_PIN, BUTTON1_PORT, &button_1_state);
	if(button_1_state==HIGH)
	{
		LED_on(PIN1_PIN, PIN1_PORT);
		LED_off(PIN2_PIN,PIN2_PORT);
	}
	else if (button_1_state==LOW)
	{
		LED_off(PIN1_PIN, PIN1_PORT);
		LED_on(PIN2_PIN,PIN2_PORT);
	}
	}
}
void testTIMER()
{
	LED_init(PIN1_PIN,PIN1_PORT);
	LED_init(PIN2_PIN,PIN2_PORT);
	setTimerConfigs();
	LED_on(PIN1_PIN,PIN1_PORT);
	LED_off(PIN2_PIN,PIN2_PORT);
	while(1)
	{
		LED_toggle(PIN1_PIN,PIN1_PORT);
		LED_toggle(PIN2_PIN,PIN2_PORT);
		delay_s(2.0);
	}
}*/
/*void testINTERRUPT()
{
	
	while(1)
	{	switch(led_number)
		{
			case 0:
			//turn off all leds
			LED_off(PIN1_PIN,PIN1_PORT);
			LED_off(PIN2_PIN,PIN2_PORT);
			break;
			case 1:
			//turn on led 1
			LED_on(PIN1_PIN,PIN1_PORT);
			break;
			case 2:
			//turn on led 2
			LED_on(PIN2_PIN,PIN2_PORT);
			break;
			case 3:
			break;
			default:
			break;
		}
	}
}
 ISR(EXT_INT_0)
 {
	 
	 if (led_number<NUMBER_OF_LEDS)
	 {
		 led_number++;
	 }
	 else
	 {
		 led_number=0;
	 }
 }
 */