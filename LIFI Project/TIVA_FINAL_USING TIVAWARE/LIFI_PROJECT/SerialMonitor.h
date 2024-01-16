/*
 * SerialMonitor.h
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */

#ifndef SERIALMONITOR_H_
#define SERIALMONITOR_H_

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

void SerialMonitor_INIT(void);

void Serial_Print( uint8_t *stringarr );

void Serial_Println( uint8_t *stringarr );

void SerialMonitor_Send_Char( uint8_t charr );

uint8_t Serial_Recieve(void);


#endif /* SERIALMONITOR_H_ */
