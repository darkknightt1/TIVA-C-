/*
 * FlameSensor.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */
#include "FlameSensor.h"

uint32_t ADC0Value =2000;

void FlameSensor_INIT(void)
{
  /* //ADC initialize
   // SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//pin E3 used for ADC input INTIALIZED already in for bletooth module
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));

    GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_3);
    ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0,ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
    ADCSequenceEnable(ADC0_BASE, 1 );*/

        SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));

        GPIOPinTypeADC(GPIO_PORTE_BASE,GPIO_PIN_3);
        ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
        ADCSequenceStepConfigure(ADC0_BASE, 0, 0,ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
        ADCSequenceEnable(ADC0_BASE, 0 );

}

uint32_t FlameSensor_Value(void)
{
    ADCIntClear(ADC0_BASE,0);
    //ADCIntEnable(ADC0_BASE,0);
    ADCProcessorTrigger(ADC0_BASE, 0);
   while(!ADCIntStatus(ADC0_BASE, 0, false));
   ADCIntClear(ADC0_BASE,0);
    ADCSequenceDataGet(ADC0_BASE, 0, &ADC0Value);
    return ADC0Value;

}


