/*
 * Mem_map32.h
 *
 * Created: 11/24/2022 10:53:55 PM
 *  Author: shaimaa farag
 */ 


#ifndef MEM_MAP32_H_
#define MEM_MAP32_H_

/***********************************/
/***Define all DIO Registers*******/
/*********************************/
//PORTA
#define  PORTA (*(volatile uint8_t*)0x3B)
#define  DDRA  (*(volatile uint8_t*)0x3A)
#define  PINA  (*(volatile uint8_t*)0x39)
//PORTB
#define  PORTB (*(volatile uint8_t*)0x38)
#define  DDRB  (*(volatile uint8_t*)0x37)
#define  PINB  (*(volatile uint8_t*)0x36)
//PORTC
#define  PORTC (*(volatile uint8_t*)0x35)
#define  DDRC  (*(volatile uint8_t*)0x34)
#define  PINC  (*(volatile uint8_t*)0x33)
//PORTD
#define  PORTD (*(volatile uint8_t*)0x32)
#define  DDRD  (*(volatile uint8_t*)0x31)
#define  PIND  (*(volatile uint8_t*)0x30)


/**********************************/
/**********Timer 0 Registers*******/
/**********************************/
#define TCNT0   (*(volatile unsigned char*)0x52)
#define TCCR0   (*(volatile unsigned char*)0x53)
#define TWCR    (*(volatile unsigned char*)0x56)
#define SPMCR   (*(volatile unsigned char*)0x57)
#define TIFR    (*(volatile unsigned char*)0x58)
#define TIMSK   (*(volatile unsigned char*)0x59)

#define OCR0    (*(volatile unsigned char*)0x5C)

/**********************************/
/**********External Interrupt*******/
/**********************************/
#define MCUCSR   (*(volatile unsigned char*)0x54)
#define ISC2 6

#define MCUCR   (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

#define GICR     (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define GIFR    (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

#define SREG	(*((volatile uint8_t *)0x5F))

#endif /* MEM_MAP32_H_ */