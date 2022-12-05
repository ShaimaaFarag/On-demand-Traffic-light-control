/*
 * app.c
 *
 * Created: 11/25/2022 1:42:18 AM
 *  Author: Dell
 */ 
#include "app.h"
volatile EN_trafficModes_t mode=normalMode;
EN_phase_t phase=CARS_MOVE;
uint8_t testPhase=1;
EN_afterBlinkPhase_t afterBlinkPhase=GOTO_CARS_STOP;





/*
*1-this function to start the traffic light application , it takes and returns nothing
*2-firs initialize leds, button , timer and interrupts
*3-then see the mode
*4-if normal mode:turn off all leds to avoid any error, then know the phase
   -if phase 1:cars green led is on and pedestrian red led is on then
	(turn on cars green led and pedestrian red led,then wait 5 seconds, then turn off cars green led and pedestrian red led ,go to next step to blink yellow led then go to phase3 )
   -if phase 2:cars yellow led is blinking and pedestrian yellow led is blinking then
    (blink car and pedestrian yellow leds for 5 seconds,then turn of yellow leds, check if after blink should go to phase1 or3)
   -if phase 3:cars red led is on and pedestrian green led is on then
    (turn on cars red led and pedestrian green led, then wait 5 seconds,turn off cars red led and pedestrian green led,then go again to blink yellow leds,after yellow leds blink phase go to first phase to turn on cars led pin )
*5-if pedestrian mode :if button pressed while cars green led or yellow led is on then
   -(turn on pedestrian red led so pedestrian can't move,then blink yellow leds for 5 seconds,//turn off pedestrian red led and both yellow leds,turn on cars red led and pedestrian green led
     then wait 5 seconds , turn off cars red led and pedestrian green led , finally turn the mode to normal mode)
*/
void appStart()
{
	//****************************************************
	//** initialize all leds,button,timer and interrups **
	//*****************************************************
	//initialize button
	buttonInit(INT0_BUTTON_PIN,INT0_BUTTON_PORT);
	
	//initialize all LEDs pins
	//LEDs_init();
	//initialize car leds
	LED_init(carRed_led_pin,carRed_led_port);
	LED_init(carYellow_led_pin,carYellow_led_port);
	LED_init(carGreen_led_pin,carGreen_led_port);
	//initialize pedestrians leds
	LED_init(pedestriansRed_led_pin,pedestriansRed_led_port);
	LED_init(pedestriansYellow_led_pin,pedestriansYellow_led_port);
	LED_init(pedestriansGreen_led_pin,pedestriansGreen_led_port);
	
	//initialize timer
	setTimerConfigs();
	
	//initialize rising edge interrupt
	risingEdgeInterrupt();
	
	//****************************************************
	//************** start the app ***********************
	//*****************************************************
	
	while(1)
	{
		if(mode==normalMode)
		{
			
			//turn all car and pedestrian leds off
			//LEDs_off();
			
			//phase 1:cars green led is on and pedestrian red led is on
			if(phase==CARS_MOVE)
			{
				//check if still in normal mode(no one pressed pedestrian button)
				if(mode==normalMode)
				{
					phase=CARS_WAIT; //to go to next step to blink yellow led
					testPhase=1;     //phase1(cars move)
					afterBlinkPhase=GOTO_CARS_STOP;
					
					//turn on cars green led and pedestrian red led
					for(uint8_t counter = 0 ; counter < 10 ; counter++)
					{
						if (mode==normalMode)
						{
							LED_on(carGreen_led_pin, carGreen_led_port);
							LED_on(pedestriansRed_led_pin,pedestriansRed_led_port);
							delay_s(0.5);
						}
						else
						break;
					}
					//LED_on(carGreen_led_pin, carGreen_led_port);
					//LED_on(pedestriansRed_led_pin,pedestriansRed_led_port);
					//wait 5 seconds
					//delay_s(5.0);
					//turn off cars green led and pedestrian red led
					LED_off(carGreen_led_pin, carGreen_led_port);
					LED_off(pedestriansRed_led_pin,pedestriansRed_led_port);
					
				}
			}
			
			//phase 2:cars yellow led is blinking and pedestrian yellow led is blinking
			if (phase==CARS_WAIT)
			{
				//check if still in normal mode(no one pressed pedestrian button)
				if (mode==normalMode)
				{
					
					testPhase=2;
					if (afterBlinkPhase==GOTO_CARS_STOP)
					{
						phase=CARS_STOP; //to go to next step cars red led is on
					}
					else if (afterBlinkPhase==GOTO_CARS_MOVE)
					{
						phase=CARS_MOVE;
					}
					
					//blink car and pedestrian yellow leds for 5 seconds
					//LEDs_yellowBlink();
					for(uint8_t counter = 0 ; counter < 10 ; counter++)
					{
						if (mode==normalMode)
						{
							LED_toggle(carYellow_led_pin,carYellow_led_port);
							LED_toggle(pedestriansYellow_led_pin,pedestriansYellow_led_port);
							delay_s(0.5);
						}
						else
						break;
					}
					
					//turn of yellow leds
					LED_off(carYellow_led_pin,carYellow_led_port);
					LED_off(pedestriansYellow_led_pin,pedestriansYellow_led_port);
					//turn off ped green led
					LED_off(pedestriansGreen_led_pin,pedestriansGreen_led_port);
				}
			}
			//phase 3:cars red led is on and pedestrian green led is on
			if (phase==CARS_STOP)
			{
				//check if still in normal mode(no one pressed pedestrian button)
				if (mode==normalMode)
				{
					phase=CARS_WAIT; //go again to blink yellow leds
					testPhase=3;
					afterBlinkPhase=GOTO_CARS_MOVE; //after yellow leds blink phase go to first phase to turn on cars led pin
					
					//turn on cars red led and pedestrian green led 
					LED_on(carRed_led_pin, carRed_led_port);
					LED_on(pedestriansGreen_led_pin,pedestriansGreen_led_port);
					//wait 5 seconds
					delay_s(5.0);
					//turn off cars red led and pedestrian green led
					LED_off(carRed_led_pin, carRed_led_port);
					LED_off(pedestriansGreen_led_pin,pedestriansGreen_led_port);
					
				}
			}
		}
		
		
		if (mode==pedestrianMode)
		{
			//if button pressed while cars green led or yellow led is on
			if (testPhase==1||testPhase==2)
			{
				//turn on pedestrian red led so pedestrian can't move
				LED_on(pedestriansRed_led_pin,pedestriansRed_led_port);
				//then blink yellow leds for 5 seconds
				//LEDs_yellowBlink();
				for(uint8_t counter = 0 ; counter < 10 ; counter++)
				{
					
					LED_toggle(carYellow_led_pin,carYellow_led_port);
					LED_toggle(pedestriansYellow_led_pin,pedestriansYellow_led_port);
					delay_s(0.5);
				}

				
				//turn off pedestrian red led and both yellow leds
				LED_off(pedestriansRed_led_pin,pedestriansRed_led_port);
				LED_off(pedestriansYellow_led_pin,pedestriansYellow_led_port);
				LED_off(carYellow_led_pin,carYellow_led_port);
				
				//turn on cars red led and pedestrian green led
				LED_on(carRed_led_pin, carRed_led_port);
				LED_on(pedestriansGreen_led_pin,pedestriansGreen_led_port);
				//wait 5 seconds
				delay_s(5);
				//turn off cars red led and pedestrian green led
				LED_off(carRed_led_pin, carRed_led_port);
				//LED_off(pedestriansGreen_led_pin,pedestriansGreen_led_port);
				
				phase=CARS_WAIT;
				afterBlinkPhase=GOTO_CARS_MOVE;
				
			}
			else
			{
				
			}
			mode=normalMode;
		}
		
	}
	
	
}

ISR(EXT_INT_0)
{
	mode=pedestrianMode;
}




/*#define PIN1_PORT PORT_A
#define PIN1_PIN  PIN1
#define PIN2_PORT PORT_A
#define PIN2_PIN  PIN7

#define BUTTON1_PORT PORT_D
#define BUTTON1_PIN  PIN2

#define  NUMBER_OF_LEDS 2
static uint8_t  led_number=0;
void testINTERRUPT(void)
{	
    buttonInit(BUTTON1_PIN,BUTTON1_PORT);
	LED_init(PIN1_PIN,PIN1_PORT);
	LED_init(PIN2_PIN,PIN2_PORT);
	risingEdgeInterrupt();	
	while(1)
	{
			  if(led_number==0)
			  {
			LED_off(PIN1_PIN,PIN1_PORT);
			LED_on(PIN2_PIN,PIN2_PORT);
			}
			if (led_number==1)
			{
				LED_toggle(PIN1_PIN,PIN1_PORT);
				LED_toggle(PIN2_PIN,PIN2_PORT);
				delay_s(1.0);
			}	
			}
}
	ISR(EXT_INT_0)
	{
		if (led_number<NUMBER_OF_LEDS)
		{led_number++;	}
		else
		{led_number=0;}
	}*/