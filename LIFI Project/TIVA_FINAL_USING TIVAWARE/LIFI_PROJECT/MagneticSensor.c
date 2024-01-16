/*
 * MagneticSensor.c
 *
 *  Created on: Dec 26, 2023
 *      Author: Omar Wessam
 */


#include "MagneticSensor.h"

void MagneticSensor_INIT(void)
{
      GPIOPinTypeGPIOInput(GPIO_PORTE_BASE,GPIO_PIN_0);
      GPIODirModeSet(GPIO_PORTE_BASE , GPIO_PIN_0,GPIO_DIR_MODE_IN);
      GPIOPadConfigSet(GPIO_PORTE_BASE, GPIO_PIN_0,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);
}

uint32_t MagneticSensor_Read(void)
{
     return GPIOPinRead(GPIO_PORTE_BASE,GPIO_PIN_0);
}
