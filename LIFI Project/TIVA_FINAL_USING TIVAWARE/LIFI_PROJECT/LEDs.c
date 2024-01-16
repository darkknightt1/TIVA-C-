/*
 * LEDs.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#include "LEDs.h"

extern uint8_t Start_App = 0;
void LEDs_INIT(void)
{
    //enable port f clk & unlock pin 0
     SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
     while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
     HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
     HWREG(GPIO_PORTF_BASE+GPIO_O_CR)  |= GPIO_PIN_0;
     /*Initialize Pin type for RGB & buttons */
     GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);//RGB
     //buttons
     GPIODirModeSet(GPIO_PORTF_BASE , GPIO_PIN_0|GPIO_PIN_4,GPIO_DIR_MODE_IN);
     GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

}

void StartStopButttonsInterrupt_INIT(void)
{
       /*interrupt enable*/
       GPIOIntRegister(GPIO_PORTF_BASE, PortFIntHandler);
       IntEnable(INT_GPIOF);
       IntMasterEnable();


       /*interrupt configuration*/
       GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_INT_PIN_0 | GPIO_INT_PIN_4 ,GPIO_FALLING_EDGE);
       GPIOIntEnable (GPIO_PORTF_BASE,GPIO_INT_PIN_0 | GPIO_INT_PIN_4);
}



void LEDs_WRITE(uint32_t HexValue)
{
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, HexValue);
}



void PortFIntHandler()
{
    if (GPIOIntStatus(GPIO_PORTF_BASE,1) == 1 )
        Start_App = 1;

    else if (GPIOIntStatus(GPIO_PORTF_BASE,1) == 16 )
        Start_App = 0;



    GPIOIntClear(GPIO_PORTF_BASE,GPIO_INT_PIN_0|GPIO_INT_PIN_4);
}

