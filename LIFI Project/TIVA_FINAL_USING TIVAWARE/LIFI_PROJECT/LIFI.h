/*
 * LIFI.h
 *
 *      Created on: Dec 30, 2023
 *      Author: Omar Wessam
 */

#ifndef LIFI_H_
#define LIFI_H_

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

void LIFI_INIT(void);

void LIFI_Send_String( uint8_t *stringarr );

void LIFI_Send_Char( uint8_t charr );
#endif /* LIFI_H_ */
