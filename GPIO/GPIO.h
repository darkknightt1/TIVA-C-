#include "tm4c123gh6pm.h"
#include "STANDARD_TYPES.h"
#include "BIT_MATH.h"




#define GPIO_OUTPUT 1
#define GPIO_INPUT 0

#define GPIO_HIGH 1
#define GPIO_LOW 0
#define GPIO_TGL 2

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7



void GPIO_PORT_INIT(uint8 PORT);
void GPIO_PIN_INIT(uint8 PORT , uint8 PIN ,uint8 DIR ,uint8 PUR );
void GPIO_WRITE_PIN(uint8 PORT ,uint8 PIN, uint8 LOGIC_VAL);
uint8 GPIO_READ_PIN(uint8 PORT ,uint8 PIN);
uint8 GPIO_READ_PORT(uint8 PORT);
void GPIO_WRITE_PORT(uint8 PORT, uint8 VAL);
