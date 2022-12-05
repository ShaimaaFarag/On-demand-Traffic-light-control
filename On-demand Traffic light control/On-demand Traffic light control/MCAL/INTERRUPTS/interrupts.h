/*
 * interrupts.h
 *
 * Created: 11/25/2022 6:29:23 PM
 *  Author: Dell
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../DIO/dio.h"

//external interrupt vector
//external interrupt vector 0
#define EXT_INT_0 __vector_1
//external interrupt vector 1
#define EXT_INT_1 __vector_2
//external interrupt vector 2
#define EXT_INT_2 __vector_3


//set global interrupts->set I-bit in status register to 1
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
//clear global interrupts->set I-bit in status register to 0
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((single,used));\
void INT_VECT(void)

void risingEdgeInterrupt(void);



#endif /* INTERRUPTS_H_ */