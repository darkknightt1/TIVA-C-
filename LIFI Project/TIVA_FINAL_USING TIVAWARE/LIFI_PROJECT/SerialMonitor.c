/*
 * SerialMonitor.c
 *
 *  Created on: Dec 25, 2023
 *      Author: Omar Wessam
 */


#include "SerialMonitor.h"

void SerialMonitor_INIT(void)
{
            /*enable uart clk*/
            SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); already enabled for A3 trigger pin
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));
            /*Initialize uart peripheral*/
            GPIOPinConfigure(GPIO_PA0_U0RX);
            GPIOPinConfigure(GPIO_PA1_U0TX);
            GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

            UARTEnable(UART0_BASE);
            UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200,//intialize uart0 , system clk ,115200 baud
            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |  UART_CONFIG_PAR_NONE));         //8bits mode , stop bit available ,no parity


}

void Serial_Print( uint8_t *stringarr )
{
    while ( *stringarr )
        UARTCharPut(UART0_BASE, *(stringarr++));

}

void Serial_Println( uint8_t *stringarr )
{

    while ( *stringarr )
        UARTCharPut(UART0_BASE, *(stringarr++));

    UARTCharPut(UART0_BASE, '\r');
    UARTCharPut(UART0_BASE, '\n');
}

void SerialMonitor_Send_Char( uint8_t charr )
{
       UARTCharPut(UART0_BASE, charr);
       UARTCharPut(UART0_BASE, '\r');
       UARTCharPut(UART0_BASE, '\n');
}

uint8_t Serial_Recieve(void)
{
    return UARTCharGet(UART0_BASE);
}
