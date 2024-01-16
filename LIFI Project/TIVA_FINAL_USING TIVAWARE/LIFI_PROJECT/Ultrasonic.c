/*
 * Ultrasonic.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#include "Ultrasonic.h"

 uint32_t UltrasonicDuration1=0;
uint32_t UltrasonicDuration2=0;
uint32_t Duration=0;
uint32_t Distance=0;


void ultrasonic_INIT(void)
{
        /*Timer3 Initialization*/
        SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER3));
        //pin B2 echo configuration
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
        GPIOPinConfigure(GPIO_PB2_T3CCP0);
        GPIOPinTypeTimer( GPIO_PORTB_BASE,GPIO_PIN_2);// GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE,GPIO_PIN_2);
        // pin A3 configuration trigger
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
        GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE,GPIO_PIN_3);


        //timer intilization
        TimerConfigure(TIMER3_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME_UP );  //up timer , split pair 16bits , capture on timeout not countout
        TimerControlEvent(TIMER3_BASE ,TIMER_A, TIMER_EVENT_BOTH_EDGES);// capture on both edges (one edge for timer counting start , one for counting stop)
        //TimerEnable ( TIMER3_BASE , TIMER_A);//start the counter



}

uint32_t ultrasonic_Distance(void)
{

           TimerEnable ( TIMER3_BASE , TIMER_A);
           GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_3, 0x00);
           SysCtlDelay(52);

           GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_3, 0x08);
           SysCtlDelay(52);

           GPIOPinWrite(GPIO_PORTA_BASE,GPIO_PIN_3, 0x00);



           TimerIntClear(TIMER3_BASE,TIMER_CAPA_EVENT);
           while ( !TimerIntStatus(TIMER3_BASE,0) );
           UltrasonicDuration1 = TimerValueGet(TIMER3_BASE,TIMER_A);

           TimerIntClear(TIMER3_BASE,TIMER_CAPA_EVENT);
           while ( !TimerIntStatus(TIMER3_BASE,0) );
           UltrasonicDuration2 = TimerValueGet(TIMER3_BASE,TIMER_A);


           Duration = (UltrasonicDuration2 - UltrasonicDuration1 ) & 0x00FFFFFF;
           Distance = (( (float) Duration  * (float) 0.00340000))/2;
           TimerDisable ( TIMER3_BASE , TIMER_A);
           return (uint32_t)Distance;

}
