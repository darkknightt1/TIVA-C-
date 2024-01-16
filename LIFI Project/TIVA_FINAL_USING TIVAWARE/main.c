/**
 * main.c
 *
 *Author : Omar Wessam
 *
 *Date   : 17/12/2023
 */
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/sysctl.h"


#include "string.h"
#include "LIFI_PROJECT/Ultrasonic.h"
#include "LIFI_PROJECT/Bluetooth.h"
#include "LIFI_PROJECT/FlameSensor.h"
#include "LIFI_PROJECT/LEDs.h"
#include "LIFI_PROJECT/SerialMonitor.h"
#include "LIFI_PROJECT/MagneticSensor.h"
#include "LIFI_PROJECT/BuzzerLedMute.h"
#include "LIFI_PROJECT/LIFI.h"




//A5 LED
//A6 BUZZER
//A7 MUTE BUTTON

//E4 BLUETOOTH
//E5 BLUETOOTH

//B2 ECHO
//E3 FLAME
//A3 TRIGGER
//E0 MAGNETIC SENSOR

//F0 START BUTTON
//F4 START BUTTON





//global variables

uint32_t flame=0;
uint32_t magnetic=0;
uint32_t distance=30;
uint8_t cThisChar;


extern uint8_t Start_App;
extern uint8_t Mute_Flag;

bool MagneticFlag=0;
bool FlameFlag=0;
bool UltrasonicFlag=0;


int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    ultrasonic_INIT();
    Bluetooth_INIT();
    SerialMonitor_INIT();
    FlameSensor_INIT();
    MagneticSensor_INIT();
    LEDs_INIT();
    LIFI_INIT();
    Mute_INIT();
    StartStopButttonsInterrupt_INIT();


    while(1)
        {
            if(Start_App)
            {
                LEDs_WRITE(0x08);
                //Bluetooth_Send_String("START");
                distance =ultrasonic_Distance();
                flame=FlameSensor_Value();
                magnetic=MagneticSensor_Read();


              if ( distance < 25 )
                {
                   UltrasonicFlag = 1;
                    //send to arduino
                    if (Mute_Flag==0)
                    {
                        Bluetooth_Send_String("Intrusion");
                        LIFI_Send_Char('1');
                    }
                    else
                    {
                        LIFI_Send_Char('A');
                        Bluetooth_Send_String("IntrusionMute");
                    }

                    Serial_Println("I");
                    SysCtlDelay(10000);
                }
              else UltrasonicFlag=0;


                if (flame<3000)
                {
                    FlameFlag=1;
                    //sendto arduino
                    if (Mute_Flag==0)
                    {
                        Bluetooth_Send_String("FIRE");
                        LIFI_Send_Char('3');
                    }

                    else
                    {
                        LIFI_Send_Char('a');
                        Bluetooth_Send_String("FIREMute");
                    }

                    Serial_Println("F");
                    SysCtlDelay(10000);
                }
                else FlameFlag=0;



                if (magnetic)
                {
                    MagneticFlag=1;
                    //sendto arduino
                    if (Mute_Flag==0)
                    {
                        Bluetooth_Send_String("DoorOpen");
                        LIFI_Send_Char('0');
                    }
                    else
                    {
                        LIFI_Send_Char('9');
                        Bluetooth_Send_String("DoorOpenEMute");
                    }

                    Serial_Println("D");
                    SysCtlDelay(10000);
                }
                else MagneticFlag=0;

                if (!MagneticFlag && !FlameFlag && !UltrasonicFlag ) {LIFI_Send_Char('<');Bluetooth_Send_String("NOTHING");}

                SysCtlDelay(1000000);
               }

            else
            {
                LEDs_WRITE(0x00);
                LIFI_Send_Char('<');
            }

        }
}
