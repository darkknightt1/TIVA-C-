/*
 * FlameSensor.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#ifndef FLAMESENSOR_H_
#define FLAMESENSOR_H_

#include <stdbool.h>
#include <stdint.h>

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"

#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "driverlib/timer.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

void FlameSensor_INIT(void);
uint32_t FlameSensor_Value(void);



#endif /* FLAMESENSOR_H_ */
