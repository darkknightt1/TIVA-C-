
#ifndef LCD_H_
#define LCD_H_

#include "STANDARD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
#include "GPIO.h"

//ports
#define LCD_cntrl_PORT PORTB
#define LCD_data_PORT  PORTA
//data pins for data port
#define LCD_D0 4
#define LCD_D1 5
#define LCD_D2 6
#define LCD_D3 7
//same data pins as we are using 4-bits system
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7


//control pins
#define LCD_RS 0   
#define LCD_RW 1
#define LCD_EN 4

//LCD conditions
#define LCD_OUT  GPIO_OUTPUT
#define LCD_LOW  GPIO_LOW
#define LCD_HIGH GPIO_HIGH



void LCD_intialize(void);
void LCD_write_command(uint8 command);
void LCD_write_character(uint8 character);
void LCD_write_string(uint8 *str);
void LCD_write_number(uint32 number);
void LCD_clear();




#endif /* LCD_CONFIGURATION_H_ */