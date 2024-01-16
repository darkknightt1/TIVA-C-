#include "KEYPAD.h"
#include "LCD.h"
void delayyy()
{
  volatile int Z=0;
  while (Z<13850)
  Z++;
}
const uint8 saved[4][4] =
{
	{'1','2','3','*'},
	{'4','5','6','/'},
	{'7','8','9','+'},
	{'=','0','#','-'}
};
void KEYPAD_Intialize (void)
{
        GPIO_PORT_INIT_portmap(PORTE);
	GPIO_PORT_INIT_portmap(PORTC);
	//setting all output to high
	GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,KEYPAD_PIN_OUT0,KEYPAD_LOW);
	GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,KEYPAD_PIN_OUT1,KEYPAD_LOW);
	GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,KEYPAD_PIN_OUT2,KEYPAD_LOW);
	GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,KEYPAD_PIN_OUT3,KEYPAD_LOW);
  
}
uint8 KEYPAD_Read (void)
{
	uint8 val=0;uint8 btn='$';
	uint8 row_loc=KEYPAD_ROW_START;
	uint8 col_loc=KEYPAD_COL_START;
	for ( ; col_loc<=KEYPAD_COL_END ; col_loc++)
	{
		GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,col_loc,KEYPAD_HIGH);
		for (;col_loc<=KEYPAD_ROW_END;row_loc++)
		{
			val= GPIO_READ_PIN(KEYPAD_PORT_IN, row_loc);
			if (val==0)
			{
				btn=saved[row_loc -KEYPAD_ROW_START] [col_loc -KEYPAD_COL_START];
                                LCD_write_character (btn);
				while (val>0)
				{
                                   val=GPIO_READ_PIN(KEYPAD_PORT_IN,row_loc);delayyy();
				}
				  delayyy();  //LCD_clear();     
			}
		}
		GPIO_WRITE_PIN_bitbanding(KEYPAD_PORT_OUT,col_loc,KEYPAD_LOW);
	}
	return btn;
}