/*
 * dio.c
 *
 * Created: 11/24/2022 11:45:12 PM
 *  Author: Dell
 */ 

//include.h
#include "dio.h"

/*
*1-this function take port number(A,B,C or D) and pin number(0,1,..,7) and the direction of this pin (as input(0) pin or as an output(1) pin)
*2-it check on the port number , then check the direction needed 
*3-if the direction of pin is input pin then clear this pin and return dio_ok, else if direction of pin is output pin then set this pin and return dio_ok, else return dio_fail
*/
//this function take port number(A,B,C or D) and pin number(0,1,..,7) and the direction of this pin (as input(0) pin or as an output(1) pin)
EN_dioError_t DIO_init (uint8_t pin, uint8_t port, uint8_t direction)
{
	EN_dioError_t errorState=DIO_OK;
	switch (port)
	{
		
		//it check on the port number
		case PORT_A:
			//then check the direction needed 
			//if the direction of pin is input pin then clear this pin and return dio_ok
			if(direction==INPUT)
				 { 
					 CLEAR_BIT(DDRA,pin);  //DDRA &=~(1<<pin);
					 errorState=DIO_OK;
				 }
			//else if direction of pin is output pin then set this pin and return dio_ok
			else if (direction==OUTPUT)
				{
					SET_BIT(DDRA,pin);	//DDRA |=(1<<pinNumber);
					errorState=DIO_OK;
				}
			//else return dio_fail
			else
				{
					errorState=DIO_FAIL;//error
				}
		return errorState;
		break;
		////////////////////////////////
		case PORT_B:
		if(direction==INPUT)
		{
			CLEAR_BIT(DDRB,pin);  //DDRA &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (direction==OUTPUT)
		{
			SET_BIT(DDRB,pin);	//DDRA |=(1<<pinNumber);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		return errorState;
		break;
		//////////////////////////////////
		case PORT_C:
		if(direction==INPUT)
		{
			CLEAR_BIT(DDRC,pin);  //DDRC &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (direction==OUTPUT)
		{
			SET_BIT(DDRC,pin);	//DDRC |=(1<<pinNumber);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		return errorState;
		break;
		//////////////////////////////
		case PORT_D:
		if(direction==INPUT)
		{
			CLEAR_BIT(DDRD,pin);  //DDRD &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (direction==OUTPUT)
		{
			SET_BIT(DDRD,pin);	//DDRD |=(1<<pinNumber);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		
		break;
		
	}
	return errorState;
}

/*
*1-this function take port number(A,B,C or D) and pin number(0,1,..,7) and the value of this pin (as low(0)  or  high(1) pin)
*2-it check on the port number , then check the value needed
*3-if the value of pin is low pin then clear this pin and return dio_ok, else if value of pin is high pin then set this pin and return dio_ok, else return dio_fail
*/
//this function take port number(A,B,C or D) and pin number(0,1,..,7) and the value of this pin (as low(0)  or  high(1) pin)
EN_dioError_t DIO_write (uint8_t pin, uint8_t port, uint8_t value)
{
	EN_dioError_t errorState=DIO_OK;
	switch (port)
	{
		
		//it check on the port number 
		case PORT_A:
		//then check the value needed
		//if the value of pin is low pin then clear this pin and return dio_ok
		if(value==LOW)
		{
			CLEAR_BIT(PORTA,pin);//PORTA &=~(1<<pin);
			errorState=DIO_OK;
		}
		//else if value of pin is high pin then set this pin and return dio_ok
		else if (value==HIGH)
		{
			SET_BIT(PORTA,pin);//PORTA |=(1<<pin);
			errorState=DIO_OK;
		}
		//else return dio_fail
		else
		{
			errorState=DIO_FAIL;//error
		}
		return errorState;
		break;
		////////////////////////////////
		case PORT_B:
		if(value==LOW)
		{
			CLEAR_BIT(PORTB,pin);//PORTB &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTB,pin);//PORTB |=(1<<pin);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		return errorState;
		break;
		///////////////////////////////
		case PORT_C:
		if(value==LOW)
		{
			CLEAR_BIT(PORTC,pin);//PORTC &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTC,pin);//PORTC |=(1<<pin);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		return errorState;
		break;
		//////////////////////////
		case PORT_D:
		if(value==LOW)
		{
			CLEAR_BIT(PORTD,pin);//PORTD &=~(1<<pin);
			errorState=DIO_OK;
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTD,pin);//PORTA |=(1<<pin);
			errorState=DIO_OK;
		}
		else
		{
			errorState=DIO_FAIL;//error
		}
		
		break;
	}
	return errorState;
}
/*
*1-this function take port number(A,B,C or D) and pin number(0,1,..,7)
*2-it check on the port number , then toggle the state of given pin in this port and return dio_ok 
*/
//this function take port number(A,B,C or D) and pin number(0,1,..,7)
EN_dioError_t DIO_toggle (uint8_t pin, uint8_t port)
{
	EN_dioError_t errorState=DIO_OK;
	////it check on the port number
	switch (port)
	{
		case PORT_A:
		//then toggle the state of given pin in this port and return dio_ok 
		TOGGLE_BIT(PORTA,pin);//PORTA ^=(1<<pinNumber);
		errorState=DIO_OK;
		break;
		
		case PORT_B:
		TOGGLE_BIT(PORTB,pin);//PORTB ^=(1<<pinNumber);
		errorState=DIO_OK;
		break;
		
		case PORT_C:
		TOGGLE_BIT(PORTC,pin);//PORTC ^=(1<<pinNumber);
		errorState=DIO_OK;
		break;
		
		case PORT_D:
		TOGGLE_BIT(PORTD,pin);//PORTD ^=(1<<pinNumber);
		errorState=DIO_OK;
		break;
		
		default:
		errorState=DIO_FAIL;
		break;
		
	}
	return errorState;

}

/*
*1-this function take port number(A,B,C or D) and pin number(0,1,..,7) and variable to store the value on it
*2-it check on the port number , then get the state of given pin in this port and store it on value and  return dio_ok
*/
//this function take port number(A,B,C or D) and pin number(0,1,..,7) and variable to store the value on it
EN_dioError_t DIO_read(uint8_t pin, uint8_t port, uint8_t *value)
{
	EN_dioError_t errorState=DIO_OK;
	//it check on the port number
	switch(port)
	{
		
		case PORT_A:
		//then get the state of given pin in this port and store it on value
		*value =(PINA&(1<<pin))>>pin;// get state->read bit
		errorState=DIO_OK;
		break;
		case PORT_B:
		*value =(PINB&(1<<pin))>>pin;// get state->read bit
		errorState=DIO_OK;
		break;
		case PORT_C:
		*value =(PINC&(1<<pin))>>pin;// get state->read bit
		errorState=DIO_OK;
		break;
		case PORT_D:
		*value =(PIND&(1<<pin))>>pin;// get state->read bit
		errorState=DIO_OK;
		break;
		default:
		errorState=DIO_FAIL;//error
		break;
		
	}
	return errorState;
}