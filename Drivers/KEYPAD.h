#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "GPIO.h"
#include "BIT_MATH.h"
#include "STANDARD_TYPES.h"

#define KEYPAD_PORT_IN  PORTC
#define KEYPAD_PORT_OUT PORTE


//coulumn portc
#define KEYPAD_PIN_INP0 4
#define KEYPAD_PIN_INP1 5
#define KEYPAD_PIN_INP2 6
#define KEYPAD_PIN_INP3 7

//row porte
#define KEYPAD_PIN_OUT0 0
#define KEYPAD_PIN_OUT1 1
#define KEYPAD_PIN_OUT2 2
#define KEYPAD_PIN_OUT3 3

#define KEYPAD_INPUT  GPIO_INPUT
#define KEYPAD_OUTPUT GPIO_OUTPUT

#define KEYPAD_LOW  GPIO_LOW
#define KEYPAD_HIGH GPIO_HIGH

#define KEYPAD_COL_START 4
#define KEYPAD_COL_END   7

#define KEYPAD_ROW_START 0
#define KEYPAD_ROW_END   3





void KEYPAD_Intialize (void);
uint8 KEYPAD_Read (void);

/*
//Define all the PINS in PortC individually
#define PORTC4      (*((volatile unsigned long *)0x40006040))     
#define PORTC5      (*((volatile unsigned long *)0x40006080))
#define PORTC6      (*((volatile unsigned long *)0x40006100))
#define PORTC7      (*((volatile unsigned long *)0x40006200))
//Define all the PINS in PortE individually
#define PORTE0      (*((volatile unsigned long *)0x40024004))    
#define PORTE1      (*((volatile unsigned long *)0x40024008))
#define PORTE2      (*((volatile unsigned long *)0x40024010))
#define PORTE3      (*((volatile unsigned long *)0x40024020))*/
#endif