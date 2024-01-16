/*
 * LEDs.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#ifndef LEDS_H_
#define LEDS_H_


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


void LEDs_INIT(void);
void LEDs_WRITE(uint32_t HexValue);
void StartStopButttonsInterrupt_INIT(void);
void PortFIntHandler();


#define GET_BIT(REG,BIT) ((REG>>BIT)&1)
#define SET_BIT(x,b) (x |=(1<<b))
#define CLR_BIT(x,b) (x=x&~(1<<b))


#endif /* LEDS_H_ */
