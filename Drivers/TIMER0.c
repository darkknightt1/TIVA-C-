#include "TIMER0.h"
#include "GPIO.h"
void TIMER0_INIT(void)
{
  SYSCTL_RCGCTIMER_R |= 0x01; 
  TIMER0_CTL_R = 0;
  //1st: Timer config
#if (TIMER0_BIT_MODE == 0) //16bit
  TIMER0_CFG_R = 0x04 ;
#elif (TIMER0_BIT_MODE == 1) //32bit
  TIMER0_CFG_R = 0x00
#elif (TIMER0_BIT_MODE == 2 )//RTC 
   TIMER0_CFG_R = 0x01;
#endif
  
  //2nd: TIMER Shot
#if (TIMER0_SHOTS == 0)   //one shot
  TIMER0_TAMR_R |= 0x01 ;
#elif (TIMER0_SHOTS == 1) //periodic
  TIMER0_TAMR_R |= 0x02;
#elif TIMER0_SHOTS == 2) //Capture 
   TIMER0_TAMR_R |= 0x03;
#endif
   
   
   //3rd: Counting mode
#if (TIMER0_Count_Mode == 0) //Upcount
  SET_BIT(TIMER0_TAMR_R,4);
#elif TIMER0_Count_Mode == 1 //DownCount
  CLR_BIT(TIMER0_TAMR_R,4);
#endif
  
  //4th: SET Prescalar
 TIMER0_TAPR_R = TIMER0_Prescalar_Value;
  
 //5th: Clear timeout flag
 TIMER0_ICR_R |= 0x01;
 
}


void TIMER0_DelayMs(uint32 TimeValue_ms)
{
  
 uint32 ReloadValue = (   (TimeValue_ms*16000)/TIMER0_Prescalar_Value)  - 1;
  //6th: CTRL modes
#if (TIMER0_CTRL_MODE == 0) //TIMER0 A
   TIMER0_TAILR_R=ReloadValue;
   TIMER0_CTL_R |=0x01;
   while(GET_BIT(TIMER0_RIS_R,0)==0);
   TIMER0_ICR_R |= 0x01;
#elif (TIMER0_CTRL_MODE == 1) //TIMER0 B
   TIMER0_TBILR_R=ReloadValue;
   SET_BIT(TIMER0_CTL_R ,8);
   while(!GET_BIT(TIMER0_RIS_R,8));
   SET_BIT(TIMER0_ICR_R ,8);
#elif (TIMER0_CTRL_MODE == 2) //TIMER0 GEN
   TIMER0_TAILR_R=ReloadValue;
   TIMER0_CTL_R |=0x01;
   while(!GET_BIT(TIMER0_RIS_R,0));
   TIMER0_ICR_R |= 0x01;
#endif  
}



uint32 i;
void Timer0_Delay(uint32 ttime)
{
    SET_BIT(RCGCTIMER,0);    //Enable clock for timer0

    CLR_BIT(GPTMCTL,0);      //Disable timer0 during configuration


    GPTMCFG=0x04;

    GPTMTAMR = 0x02;     //Select one shot timer& Down count selection

    GPTMTAILR = 16-1;  //Set clock to 16MHZ
    SET_BIT(GPTMICR,0);       //Clear flag

    SET_BIT(GPTMCTL,0);        //Enable timer0
    for(i=0;i<(ttime/2);i++)
    {
        while((GET_BIT(GPTMRIS,0))==0); //wait for TimerA timeout flag to set*/
        SET_BIT(GPTMICR,0);       //Clear flag
    }
}

void Timer3_Count_Init(void){


    SET_BIT(RCGCTIMER,3);    //Enable clock for timer3
    
    //SET_BIT(RCGCGPIO,1);            //enable GPIO clock
    GPIO_PORT_INIT(PORTB);
    CLR_BIT(GPIO_PORTB_DIR_R,2);        //enable GPIO clock
    SET_BIT(GPIO_PORTB_DEN_R,2);        //enable GPIO clock
    SET_BIT(GPIO_PORTB_AFSEL_R,2);        //enable GPIO clock

   
    GPIO_PORTB_PCTL_R  &=~0x00000F00;
    GPIO_PORTB_PCTL_R  |= 0x00000700;       

    CLR_BIT(GPTMCTL3,0);      //Disable timer0 during configuration


    GPTMCFG3=0x04;//16 bit mode

    GPTMTAMR3 = 0x17;     //capture mode & edge time mode & up count
//    GPTAMATCHR3 = 0xFFFF;
  //  GPTMTAPMR3 = 0xFF;
  
    
    SET_BIT(GPTMCTL3, 2);
    SET_BIT(GPTMCTL3, 3);
    //clear 3
    SET_BIT(GPTMCTL3,0);        //Enable timer3 to start counting
}

uint32 Timer3_Count_Ret(void){

    SET_BIT(GPTMICR3,2);
    while(GET_BIT(GPTMRIS3, 2)==0){} //catch rising edge
    uint32 duration1 =  GPTMTAR3;


    SET_BIT(GPTMICR3,2);
    while(GET_BIT(GPTMRIS3, 2)==0){} //catch falling edge
    uint32 duration2 =   GPTMTAR3;

    return ( duration2 -duration1) & 0x00FFFFFF ;//;/16

}

