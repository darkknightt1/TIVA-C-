/*
 * BuzzerLedMute.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Omar Wessam
 */

#include "BuzzerLedMute.h"
uint8_t Mute_Flag = 0;
void Mute_INIT(void)
{
    //GPIOPinTypeGPIOInput(GPIO_PORTA_BASE,GPIO_PIN_7);
    GPIODirModeSet(GPIO_PORTA_BASE , GPIO_PIN_7,GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTA_BASE, GPIO_PIN_7,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPD);
       /*Interrupt enable for mute button A7*/
       GPIOIntRegister(GPIO_PORTA_BASE, PortAIntHandler);
       IntEnable(INT_GPIOA);
       //IntMasterEnable(); already enabled
       /*interrupt configuration*/
       GPIOIntTypeSet(GPIO_PORTA_BASE,GPIO_INT_PIN_7 ,GPIO_FALLING_EDGE);
       GPIOIntEnable (GPIO_PORTA_BASE,GPIO_INT_PIN_7);




       //SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
      // while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1));
      // TimerConfigure(TIMER1_BASE, TIMER_CFG_SPLIT_PAIR|TIMER_CFG_A_PERIODIC);
       //TimerPrescaleSet(TIMER1_BASE,TIMER_A,0);

}



void PortAIntHandler(void)
{
    if (GPIOIntStatus(GPIO_PORTA_BASE,1) == 128 )
            Mute_Flag ^= (1<<0);

        GPIOIntClear(GPIO_PORTA_BASE,GPIO_INT_PIN_7);

}




void Delay_MicroSecond(uint32_t time)
{
    TimerLoadSet (TIMER1_BASE, TIMER_A,16-1) ;
    TimerEnable(TIMER1_BASE, TIMER_A);
    uint32_t i;
    for(i=0; i<time ; i++)
    {
        while(TimerIntStatus(TIMER1_BASE,0)==0);
        TimerIntClear(TIMER1_BASE , TIMER_TIMA_TIMEOUT);
    }
}
