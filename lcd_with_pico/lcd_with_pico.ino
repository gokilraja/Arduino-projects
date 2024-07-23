#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("NO Accident HERE");
  lcd.setCursor(0,1);
  lcd.print("Drive to safe!");
  delay(1000);
 Serial.begin(9600);
}
void loop()
{
  lcd.print("Hello world!!!");
}
