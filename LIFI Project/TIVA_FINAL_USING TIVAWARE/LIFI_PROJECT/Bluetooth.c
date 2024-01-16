/*
 * Bletooth.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */


#include "Bluetooth.h"

void Bluetooth_INIT(void)
{
            /*enable uart clk*/
            SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
            SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); already enabled for A3 trigger pin
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART5));
            /*Initialize uart peripheral*/
            GPIOPinConfigure(GPIO_PE4_U5RX);
            GPIOPinConfigure(GPIO_PE5_U5TX);
            GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

            UARTEnable(UART5_BASE);
            UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 9600,//intialize uart0 , system clk ,115200 baud
            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |  UART_CONFIG_PAR_NONE));         //8bits mode , stop bit available ,no parity


}

void Bluetooth_Send_String( uint8_t *stringarr )
{
        while ( *stringarr )
            UARTCharPut(UART5_BASE, *(stringarr++));
        UARTCharPut(UART5_BASE, '\r');
        UARTCharPut(UART5_BASE, '\n');
}

void Bluetooth_Send_Char( uint8_t charr )
{
        UARTCharPut(UART5_BASE, charr);
        UARTCharPut(UART5_BASE, '\r');
}
