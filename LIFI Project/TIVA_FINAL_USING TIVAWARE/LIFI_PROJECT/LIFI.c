/*
 * LIFI.c
 *
 *  Created on: Dec 30, 2023
 *      Author: Omar Wessam
 */
#include "LIFI.h"

void LIFI_INIT(void)
{
            /*enable uart clk*/
            SysCtlPeripheralEnable(SYSCTL_PERIPH_UART7);
            //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); already enabled for A3 trigger pin
            while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART7));
            /*Initialize uart peripheral*/
           // GPIOPinConfigure(GPIO_PE4_U5RX);
            GPIOPinConfigure(GPIO_PE1_U7TX);
            GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_1 );

            UARTEnable(UART7_BASE);
            UARTConfigSetExpClk(UART7_BASE, SysCtlClockGet(), 9600,//intialize uart0 , system clk ,115200 baud
            (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |  UART_CONFIG_PAR_NONE));         //8bits mode , stop bit available ,no parity


}

void LIFI_Send_String( uint8_t *stringarr )
{
        while ( *stringarr )
            UARTCharPut(UART7_BASE, *(stringarr++));
        UARTCharPut(UART7_BASE, '\r');
        UARTCharPut(UART7_BASE, '\n');
}

void LIFI_Send_Char( uint8_t charr )
{
        UARTCharPut(UART7_BASE, charr);
        UARTCharPut(UART7_BASE, '\r');
        UARTCharPut(UART7_BASE, '\n');
}


