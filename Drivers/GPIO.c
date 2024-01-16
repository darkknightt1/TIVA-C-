#include "GPIO.h"

/*7/11/2023 using normal method*/

void GPIO_PORT_INIT(uint8 PORT)
{

  switch (PORT)
  {
    case PORTA: SYSCTL_RCGCGPIO_R |=PORTA; while(SYSCTL_PRGPIO_R0==0){}; GPIO_PORTA_LOCK_R= 0x4c4f434b;   break;                                                                         
    case PORTB: SYSCTL_RCGCGPIO_R |=PORTB; while(SYSCTL_PRGPIO_R1==0){}; GPIO_PORTB_LOCK_R= 0x4c4f434b;   break;                                                                                                                                                                          
    case PORTC: SYSCTL_RCGCGPIO_R |=PORTC; while(SYSCTL_PRGPIO_R2==0){}; GPIO_PORTC_LOCK_R= 0x4c4f434b;   break;                                                                                                                                                                                  
    case PORTD: SYSCTL_RCGCGPIO_R |=PORTD; while(SYSCTL_PRGPIO_R3==0){}; GPIO_PORTD_LOCK_R= 0x4c4f434b;   break;                                                                                              
    case PORTE: SYSCTL_RCGCGPIO_R |=PORTE; while(SYSCTL_PRGPIO_R4==0){}; GPIO_PORTE_LOCK_R= 0x4c4f434b;   break;                                                                                                                                                                        
    case PORTF: SYSCTL_RCGCGPIO_R |=PORTF; while(SYSCTL_PRGPIO_R5==0){}; GPIO_PORTF_LOCK_R= 0x4c4f434b;   break;

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
return 0;
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
  return 0;

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
/*----------------------------------------------------------------------------------------------------------------------------------*/





/*Using Port Map method*/

void GPIO_PORT_INIT_portmap(uint8 PORT)
{
  SYSCTL_RCGCGPIO_R |=PORT;
  switch (PORT)
  {
    case PORTA: while(SYSCTL_PRGPIO_R0==0){}; GPIO_PORTA_LOCK_R= 0x4c4f434b; GPIO_PORTA_CR_R |= PORTA_DEN;    GPIO_PORTA_DEN_R |= PORTA_DEN;        GPIO_PORTA_DIR_R |= PORTA_DIR;  GPIO_PORTA_PUR_R |= PORTA_PUR;    GPIO_PORTA_PDR_R |= PORTA_PDR;    break;                                                                         
    case PORTB: while(SYSCTL_PRGPIO_R1==0){}; GPIO_PORTB_LOCK_R= 0x4c4f434b; GPIO_PORTB_CR_R |= PORTB_DEN;    GPIO_PORTB_DEN_R |= PORTB_DEN;        GPIO_PORTB_DIR_R |= PORTB_DIR;  GPIO_PORTB_PUR_R |= PORTB_PUR;    GPIO_PORTB_PDR_R |= PORTB_PDR;    break;                                                                                                                                                                          
    case PORTC: while(SYSCTL_PRGPIO_R2==0){}; GPIO_PORTC_LOCK_R= 0x4c4f434b; GPIO_PORTC_CR_R |= PORTC_DEN;    GPIO_PORTC_DEN_R |= PORTC_DEN;        GPIO_PORTC_DIR_R |= PORTC_DIR;  GPIO_PORTC_PUR_R |= PORTC_PUR;    GPIO_PORTC_PDR_R |= PORTC_PDR;    break;                                                                                                                                                                                  
    case PORTD: while(SYSCTL_PRGPIO_R3==0){}; GPIO_PORTD_LOCK_R= 0x4c4f434b; GPIO_PORTD_CR_R |= PORTD_DEN;    GPIO_PORTD_DEN_R |= PORTD_DEN;        GPIO_PORTD_DIR_R |= PORTD_DIR;  GPIO_PORTD_PUR_R |= PORTD_PUR;    GPIO_PORTD_PDR_R |= PORTD_PDR;    break;                                                                                              
    case PORTE: while(SYSCTL_PRGPIO_R4==0){}; GPIO_PORTE_LOCK_R= 0x4c4f434b; GPIO_PORTE_CR_R |= PORTE_DEN;    GPIO_PORTE_DEN_R |= PORTE_DEN;        GPIO_PORTE_DIR_R |= PORTE_DIR;  GPIO_PORTE_PUR_R |= PORTE_PUR;    GPIO_PORTE_PDR_R |= PORTE_PDR;    break;
    case PORTF: while(SYSCTL_PRGPIO_R5==0){}; GPIO_PORTF_LOCK_R= 0x4c4f434b; GPIO_PORTF_CR_R |= PORTF_DEN;    GPIO_PORTF_DEN_R |= PORTF_DEN;        GPIO_PORTF_DIR_R |= PORTF_DIR;  GPIO_PORTF_PUR_R |= PORTF_PUR;    GPIO_PORTF_PDR_R |= PORTF_PDR;    break;

  }
  
}




/*Using Bit Banding*/
void GPIO_WRITE_PIN_bitbanding(uint8 PORT ,uint8 HEX_PIN, uint8 LOGIC_VAL)
{
  
  HEX_PIN=(1<<HEX_PIN);
  if (LOGIC_VAL == GPIO_HIGH)
    {
      switch(PORT)
      {
        case PORTA: GPIO_PORTA_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
        case PORTB: GPIO_PORTB_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
        case PORTC: GPIO_PORTC_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
        case PORTD: GPIO_PORTD_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
        case PORTE: GPIO_PORTE_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
        case PORTF: GPIO_PORTF_DATA_BITS_R[HEX_PIN] = HEX_PIN; break;
     }
    }
    else if (LOGIC_VAL == GPIO_LOW)
    {
      
      switch(PORT)
      {
        case PORTA: GPIO_PORTA_DATA_BITS_R[HEX_PIN] = 0; break;
        case PORTB: GPIO_PORTB_DATA_BITS_R[HEX_PIN] = 0; break;
        case PORTC: GPIO_PORTC_DATA_BITS_R[HEX_PIN] = 0; break;
        case PORTD: GPIO_PORTD_DATA_BITS_R[HEX_PIN] = 0; break;
        case PORTE: GPIO_PORTE_DATA_BITS_R[HEX_PIN] = 0; break;
        case PORTF: GPIO_PORTF_DATA_BITS_R[HEX_PIN] = 0; break;
    
    }
    }
    
    else if (LOGIC_VAL == GPIO_TGL)
   {
     switch(PORT)
      {
        case PORTA: GPIO_PORTA_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
        case PORTB: GPIO_PORTB_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
        case PORTC: GPIO_PORTC_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
        case PORTD: GPIO_PORTD_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
        case PORTE: GPIO_PORTE_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
        case PORTF: GPIO_PORTF_DATA_BITS_R[HEX_PIN] ^= HEX_PIN; break;
     
   }
  
  }

}
                                          
/*
void SETBIT(unsigned long volatile *REG,uint8 bit)
{
  *REG|=(1<<bit);
}
 
  for (int i=0;i<6;i++)
  {
    if (PORT[i])//if there is a value in the port[i] then intialize the port relative to it
    {
      SYSCTL_RCGCGPIO_R |= (1<<i);
      while (GET_BIT(SYSCTL_PRGPIO ,i)==0){}; 
      GPIO_PORTA_LOCK_R= 0x4c4f434b;
    }
*/