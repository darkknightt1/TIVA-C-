#include "GPIO.h"

void GPIO_PORT_INIT(uint8 PORT)
{

  switch (PORT)
  {
    case PORTA:
      SYSCTL_RCGCGPIO_R |= 0x01; while(SYSCTL_PRGPIO_R0==0){}; GPIO_PORTA_LOCK_R= 0x4c4f434b;   break;
                                                                                              
    case PORTB:                                                                               
      SYSCTL_RCGCGPIO_R |= 0x02; while(SYSCTL_PRGPIO_R1==0){}; GPIO_PORTB_LOCK_R= 0x4c4f434b;    break;
                                                                                              
    case PORTC:                                                                               
      SYSCTL_RCGCGPIO_R |= 0x04; while(SYSCTL_PRGPIO_R2==0){}; GPIO_PORTC_LOCK_R= 0x4c4f434b;    break;
                                                                                              
    case PORTD:                                                                               
      SYSCTL_RCGCGPIO_R |= 0x08; while(SYSCTL_PRGPIO_R3==0){}; GPIO_PORTD_LOCK_R= 0x4c4f434b;   break;
                                                                                              
    case PORTE:                                                                               
      SYSCTL_RCGCGPIO_R |= 0x10; while(SYSCTL_PRGPIO_R4==0){}; GPIO_PORTE_LOCK_R= 0x4c4f434b;   break;
                                                                                              
    case PORTF:                                                                               
      SYSCTL_RCGCGPIO_R |= 0x20; while(SYSCTL_PRGPIO_R5==0){}; GPIO_PORTF_LOCK_R= 0x4c4f434b;   break;

  
  }
  
}

void GPIO_PIN_INIT(uint8 PORT , uint8 PIN ,uint8 DIR ,uint8 PUR )
{
  
  if (DIR == GPIO_OUTPUT)
  {
    switch (PORT)
  {
    case PORTA: GPIO_PORTA_CR_R|= (1<<PIN);  GPIO_PORTA_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTA_DIR_R,PIN);   break;
    case PORTB: GPIO_PORTB_CR_R|= (1<<PIN);  GPIO_PORTB_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTB_DIR_R,PIN);   break;
    case PORTC: GPIO_PORTC_CR_R|= (1<<PIN);  GPIO_PORTC_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTC_DIR_R,PIN);   break;
    case PORTD: GPIO_PORTD_CR_R|= (1<<PIN);  GPIO_PORTD_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTD_DIR_R,PIN);   break; 
    case PORTE: GPIO_PORTE_CR_R|= (1<<PIN);  GPIO_PORTE_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTE_DIR_R,PIN);   break;
    case PORTF: GPIO_PORTF_CR_R|= (1<<PIN);  GPIO_PORTF_DEN_R |=(1<<PIN); SET_BIT(GPIO_PORTF_DIR_R,PIN);   break;
  }
  
  }
  else if (DIR == GPIO_INPUT)
  {
    if (PUR==1)
    {
      switch (PORT)
     {
      case PORTA: GPIO_PORTA_CR_R|= (1<<PIN);  GPIO_PORTA_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTA_DIR_R,PIN); SET_BIT(GPIO_PORTA_PUR_R,PIN); break;
      case PORTB: GPIO_PORTB_CR_R|= (1<<PIN);  GPIO_PORTB_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTB_DIR_R,PIN); SET_BIT(GPIO_PORTB_PUR_R,PIN); break;
      case PORTC: GPIO_PORTC_CR_R|= (1<<PIN);  GPIO_PORTC_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTC_DIR_R,PIN); SET_BIT(GPIO_PORTC_PUR_R,PIN); break;
      case PORTD: GPIO_PORTD_CR_R|= (1<<PIN);  GPIO_PORTD_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTD_DIR_R,PIN); SET_BIT(GPIO_PORTD_PUR_R,PIN); break; 
      case PORTE: GPIO_PORTE_CR_R|= (1<<PIN);  GPIO_PORTE_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTE_DIR_R,PIN); SET_BIT(GPIO_PORTE_PUR_R,PIN); break;
      case PORTF: GPIO_PORTF_CR_R|= (1<<PIN);  GPIO_PORTF_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTF_DIR_R,PIN); SET_BIT(GPIO_PORTF_PUR_R,PIN); break;
     }
    }
     
     else 
     {
       switch (PORT)
       {
      case PORTA: GPIO_PORTA_CR_R|= (1<<PIN);  GPIO_PORTA_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTA_DIR_R,PIN); CLR_BIT(GPIO_PORTA_PUR_R,PIN);  break;
      case PORTB: GPIO_PORTB_CR_R|= (1<<PIN);  GPIO_PORTB_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTB_DIR_R,PIN); CLR_BIT(GPIO_PORTB_PUR_R,PIN);  break;
      case PORTC: GPIO_PORTC_CR_R|= (1<<PIN);  GPIO_PORTC_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTC_DIR_R,PIN); CLR_BIT(GPIO_PORTC_PUR_R,PIN);  break;
      case PORTD: GPIO_PORTD_CR_R|= (1<<PIN);  GPIO_PORTD_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTD_DIR_R,PIN); CLR_BIT(GPIO_PORTD_PUR_R,PIN);  break; 
      case PORTE: GPIO_PORTE_CR_R|= (1<<PIN);  GPIO_PORTE_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTE_DIR_R,PIN); CLR_BIT(GPIO_PORTE_PUR_R,PIN);  break;
      case PORTF: GPIO_PORTF_CR_R|= (1<<PIN);  GPIO_PORTF_DEN_R |=(1<<PIN); CLR_BIT(GPIO_PORTF_DIR_R,PIN); CLR_BIT(GPIO_PORTF_PUR_R,PIN);  break;
      }
  
       
     
     }
  
    
    
    }
    
  

}




void GPIO_WRITE_PIN(uint8 PORT ,uint8 PIN, uint8 LOGIC_VAL)
{
  if (LOGIC_VAL == GPIO_HIGH)
    {
      switch(PORT)
      {
      case PORTA: SET_BIT(GPIO_PORTA_DATA_R,PIN); break;
      case PORTB: SET_BIT(GPIO_PORTB_DATA_R,PIN); break;
      case PORTC: SET_BIT(GPIO_PORTC_DATA_R,PIN); break;
      case PORTD: SET_BIT(GPIO_PORTD_DATA_R,PIN); break;
      case PORTE: SET_BIT(GPIO_PORTE_DATA_R,PIN); break;
      case PORTF: SET_BIT(GPIO_PORTF_DATA_R,PIN); break;
     }
    }
    else if (LOGIC_VAL == GPIO_LOW)
    {
      
      switch(PORT)
      {
      case PORTA: CLR_BIT(GPIO_PORTA_DATA_R,PIN); break;
      case PORTB: CLR_BIT(GPIO_PORTB_DATA_R,PIN); break;
      case PORTC: CLR_BIT(GPIO_PORTC_DATA_R,PIN); break;
      case PORTD: CLR_BIT(GPIO_PORTD_DATA_R,PIN); break;
      case PORTE: CLR_BIT(GPIO_PORTE_DATA_R,PIN); break;
      case PORTF: CLR_BIT(GPIO_PORTF_DATA_R,PIN); break;
    
    }
    }
    
    else if (LOGIC_VAL == GPIO_TGL)
   {
     switch(PORT)
      {
      case PORTA: TGL_BIT(GPIO_PORTA_DATA_R,PIN); break;
      case PORTB: TGL_BIT(GPIO_PORTB_DATA_R,PIN); break;
      case PORTC: TGL_BIT(GPIO_PORTC_DATA_R,PIN); break;
      case PORTD: TGL_BIT(GPIO_PORTD_DATA_R,PIN); break;
      case PORTE: TGL_BIT(GPIO_PORTE_DATA_R,PIN); break;
      case PORTF: TGL_BIT(GPIO_PORTF_DATA_R,PIN); break;
     
   }
  
  }
}




uint8 GPIO_READ_PIN(uint8 PORT ,uint8 PIN)
{
  switch(PORT)
  {
     case PORTA: return GET_BIT(GPIO_PORTA_DATA_R,PIN); break;
     case PORTB: return GET_BIT(GPIO_PORTB_DATA_R,PIN); break;
     case PORTC: return GET_BIT(GPIO_PORTC_DATA_R,PIN); break;
     case PORTD: return GET_BIT(GPIO_PORTD_DATA_R,PIN); break;
     case PORTE: return GET_BIT(GPIO_PORTE_DATA_R,PIN); break;
     case PORTF: return GET_BIT(GPIO_PORTF_DATA_R,PIN); break;
      
  }

}

uint8 GPIO_READ_PORT(uint8 PORT)
{
  switch(PORT)
  {
     case PORTA: return GPIO_PORTA_DATA_R; break;
     case PORTB: return GPIO_PORTB_DATA_R; break;
     case PORTC: return GPIO_PORTC_DATA_R; break;
     case PORTD: return GPIO_PORTD_DATA_R; break;
     case PORTE: return GPIO_PORTE_DATA_R; break;
     case PORTF: return GPIO_PORTF_DATA_R; break;
      
  }

}

void GPIO_WRITE_PORT(uint8 PORT, uint8 VAL)
{
  switch(PORT)
  {
     case PORTA: GPIO_PORTA_DATA_R=VAL; break;
     case PORTB: GPIO_PORTB_DATA_R=VAL; break;
     case PORTC: GPIO_PORTC_DATA_R=VAL; break;
     case PORTD: GPIO_PORTD_DATA_R=VAL; break;
     case PORTE: GPIO_PORTE_DATA_R=VAL; break;
     case PORTF: GPIO_PORTF_DATA_R=VAL; break;
      
  }

}


                                          
                                          
/*
  for (int i=0;i<6;i++)
  {
    if (PORT[i])//if there is a value in the port[i] then intialize the port relative to it
    {
      SYSCTL_RCGCGPIO_R |= (1<<i);
      while (GET_BIT(SYSCTL_PRGPIO ,i)==0){}; 
      GPIO_PORTA_LOCK_R= 0x4c4f434b;
    }
*/