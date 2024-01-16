#include "GPIO.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "BIT_MATH.h"
#include "STANDARD_TYPES.h"
#include "SYSTICK.h"
#include "string.h"
#include "TIMER0.h"
#include "ultrasonic.h"

#define SW0 0
#define SW4 4

#define RED_LED   1
#define BLUE_LED  2
#define GREEN_LED 3

void delayy()
{
   volatile int x=0;
   while (x<138500)
     x++;
}
int main()
{ 
    GPIO_PORT_INIT(PORTF);
    GPIO_PIN_INIT(PORTF, GPIO_PIN1, GPIO_OUTPUT,0);
    
    Timer3_Count_Init();

    
    GPIO_PORT_INIT(PORTA);
    GPIO_PIN_INIT(PORTA, GPIO_PIN3, GPIO_OUTPUT,0);
   // GPIO_PORT_INIT_portmap  (PORTF);
    uint32 distance = 0 ;
    
    while (1)
    { 
       
        distance = ultrasonic_1();
        if (distance<20) //lw el distance a2l mn 20 cm ynwr el led
        {
           GPIO_WRITE_PIN (PORTF,GPIO_PIN1,GPIO_HIGH);
           delayy();
        }
        else
        {
            GPIO_WRITE_PIN (PORTF,GPIO_PIN1,GPIO_LOW);
            delayy();
        }
 
    }
}












































/*void delayy ()
{
  volatile int x=0;
  while (x<138500) x++;
}*/






























































/*void Calculate_Print(uint8 first,uint8 operation,uint8 second)
{
 
   uint32 f=atoi(first);
   uint32 s=atoi(second);
   switch (operation)
   {
      case '+':
      LCD_write_number( f+s );
      break;
      
      case'-':
        LCD_write_number( f-s );
      break;
      
      case'/':
        LCD_write_number( f/s );
      break;
      
      case '*':
        LCD_write_number( f*s );
      break;
   
   }

}*/
/*
int main()
{
    
    LCD_intialize ();  
    KEYPAD_Intialize();

  while(1)
  {

    LCD_clear();
    LCD_write_string("Enter First Number");
    keypadreading = KEYPAD_Read();
    while (keypadreading=='$') //default value when no key is pressed
    {
      keypadreading = KEYPAD_Read();
      delayy();
    }
    first = keypadreading;
    
    
    LCD_clear();
    LCD_write_string("Enter operation");
    keypadreading = KEYPAD_Read();
    while (keypadreading=='$') //default value when no key is pressed
    {
      keypadreading = KEYPAD_Read();
      delayy();
    }
    operation = keypadreading;
    
    LCD_clear();
    LCD_write_string("Enter second Number");
    keypadreading = KEYPAD_Read();
    while (keypadreading=='$') //default value when no key is pressed
    {
      keypadreading = KEYPAD_Read();
      delayy();
    }
    second = keypadreading;
    
    
    LCD_clear();
    keypadreading = KEYPAD_Read();
    while (keypadreading!= '=')
    {
      keypadreading = KEYPAD_Read();
    }
    Calculate_Print(first,operation,second);
    
    
    
    
      if (keypadreading != '0')
      GPIO_WRITE_PIN(PORTF,RED_LED,GPIO_HIGH);
     else 
       GPIO_WRITE_PIN(PORTF,RED_LED,GPIO_LOW)

    //LCD_write_string("El-meshatshash");
   //LCD_write_character (keypadreading);
   // delayy();
   // LCD_clear();
   // while (GPIO_READ_PIN (PORTF,SW0)==0)
    //  GPIO_WRITE_PIN (PORTF,RED_LED,GPIO_HIGH);
   
    
   // GPIO_WRITE_PIN (PORTF,RED_LED,GPIO_LOW);
  }
  
   
}*/

    //GPIO_P   // GPIO_WRITE_PIN(PORTF,RED_LED,GPIO_TGL);
   // SYSTICK_Delay_ms(1000);
   // while ( SYSTICK_IS_TIME_OUT() == 0);ORT_INIT_portmap(PORTF);
    //GPIO_WRITE_PIN(PORTF,RED_LED,GPIO_HIGH);
    //SYSTICK_INIT();
    //return 0;