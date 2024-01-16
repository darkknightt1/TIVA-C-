/*
 * Ultrasonic.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

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


void ultrasonic_INIT(void);

uint32_t ultrasonic_Distance(void);




#endif /* ULTRASONIC_H_ */
