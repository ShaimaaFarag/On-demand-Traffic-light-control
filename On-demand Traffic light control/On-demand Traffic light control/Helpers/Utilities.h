/*
 * Utilities.h
 *
 * Created: 11/24/2022 11:05:55 PM
 *  Author: Dell
 */ 


#ifndef UTILITIES_H_
#define UTILITIES_H_

 
#define  SET_BIT(VAR,BIT)					  VAR |= (1<<(BIT))
#define  TOGGLE_BIT(VAR,BIT)				  VAR ^= (1<<(BIT))
#define  CLEAR_BIT(VAR,BIT)					  VAR &= ~(1<<(BIT))
#define  GET_BIT(VAR,BIT)					 (VAR>>BIT) & 1
#define  WRITE_BIT(VAR,BIT,DATA)			 (VAR)=(VAR&(~(1<<BIT)))|(DATA<<BIT)


#endif /* UTILITIES_H_ */