#include "LCD.h"
#include "string.h"


void delay()
{
  volatile int X=0;
  while (X<1385)
    X++;
}

void LCD_intialize(void)
{       //intialize PORTA and PORTB pins first  ,  "set direction as output "
        GPIO_PORT_INIT_portmap(PORTA);
        GPIO_PORT_INIT_portmap(PORTB);
        
       /* GPIO_PORTB_AMSEL_R &= 0x00;        // 3) disable analog function
        GPIO_PORTB_PCTL_R &= 0x00000000;
        GPIO_PORTB_AFSEL_R &= 0x00;
        
        GPIO_PORTA_AMSEL_R &= 0x00;        // 3) disable analog function
        GPIO_PORTA_PCTL_R  &= 0x00000000; 
        GPIO_PORTA_AFSEL_R &= 0x00;*/
        
	//initialization command from the data sheet 
	LCD_write_command(0X33);
	LCD_write_command(0X32);
	LCD_write_command(0X28);
	
        LCD_write_command(0X01);//clear display
	LCD_write_command(0X02);//go to home
	LCD_write_command(0X06);//shift cursor to the right
	LCD_write_command(0X0C);//display on ,cursor off
        
}
void LCD_write_command(uint8 command)
{
	//select the COMMAND register
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_RS,LCD_LOW);
	//select write on screen
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_RW,LCD_LOW);
	//insure enable is low"default is low ,just insuring"
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	//set the high nibble
	//GPIO_WRITE_PORT( LCD_data_PORT ,(command & 0XF0));
        GPIO_PORTA_DATA_R=command & 0XF0; 
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	delay();
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	//set the LOW nibble 
	//GPIO_WRITE_PORT( LCD_data_PORT   ,((command & 0X0F)<<4 ));
        GPIO_PORTA_DATA_R=(command & 0X0F)<<4;
        
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	delay();
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	delay();
}
void LCD_write_character(uint8 character)
{
	//select the DATA register
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_RS,LCD_HIGH);
	//select write on screen
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_RW,LCD_LOW);
	//insure enable is low "default is low ,just insuring"
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
        
	//set the high nibble
	//GPIO_WRITE_PORT( LCD_data_PORT , (character & 0XF0) );
        GPIO_PORTA_DATA_R=(character & 0XF0);
        
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	delay();
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	
	//set the LOW nibble
	//GPIO_WRITE_PORT( LCD_data_PORT ,( (character & 0X0F)<<4));
        GPIO_PORTA_DATA_R=(character & 0X0F)<<4;

        //HIGH 1ms pulse to the enable pin
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_HIGH);
	delay();
	GPIO_WRITE_PIN(LCD_cntrl_PORT,LCD_EN,LCD_LOW);
	delay();
        delay(); 
   
}

void LCD_clear()
{
	LCD_write_command(0X01);
	delay();
	delay();
        
	//LCD_write_command(0X80);
}

void LCD_write_string(uint8 *str)
{
	for (int i=0;str[i]!='\0';i++)
	{
		LCD_write_character(str[i]);
		delay();
	}
}
void LCD_write_number(uint32 number)
{
	uint8 num[16];
	ltoa(number, (uint8*)num,10);
	LCD_write_string(num);
}