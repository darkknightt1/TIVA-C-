#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define LED 10 
#define BUZZER 11

char Old_Data= '#';
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.begin(9600);
  // initialize the LCD
  lcd.begin();
  lcd.backlight();

}

void loop()
{
  if (Serial.available())
  {
    char Data = (char)Serial.read() ;
    Serial.println(Data);
    Serial.end();
    Serial.begin(9600);
    delay(1);
    if (Data == Old_Data)
    {
      Old_Data = Data;
      Data = '#';//any un-used character to avoid over printinting 
    }   
    else 
       Old_Data = Data;
    
    switch (Data)
    {
      case 'f':
        lcd.clear();
        lcd.print("FIRE");
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        break;
      case 'O':
        lcd.clear();
        lcd.print("FIRE");
        delay(5000);
        digitalWrite(BUZZER, LOW);
        break;






      case 'g':
        lcd.clear();
        lcd.print("INTRUSION");
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        break;
      case '_':
        lcd.clear();
        lcd.print("INTRUSION");
        delay(5000);
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
        break;






      case 'V':
        lcd.clear();
        lcd.print("DOOR OPEN");
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
        break;
      case 'c':
        lcd.clear();
        lcd.print("DOOR OPEN");
        delay(5000);
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
        break;

      case 'X':
        lcd.clear();
        lcd.print("NOTHING");
        delay(300);
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
        break;
        
    }
    
  }
}
