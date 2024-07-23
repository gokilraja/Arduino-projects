#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);
SoftwareSerial mySerial(0,1); // RX, TX
void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("NO Accident HERE");
  lcd.setCursor(0,1);
	lcd.print("Drive to safe!");
  delay(1000);
 Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for Leonardo only
//  }
  mySerial.begin(9600);
}
void loop()
{
//  char al=0;
//  int a=1;
//  while(a>=19){
  
  if (mySerial.available()){
     lcd.clear();
    String a1=mySerial.readString();
    lcd.setCursor(0,0);
    lcd.print("1 Accident find!");
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("  lat & lon is|");
    delay(1000);
    lcd.setCursor(0,1);
    lcd.print(a1);
//    Serial.print(mySerial.readString());
//    a=a+1;
  }
  
 
//  lcd.print(al);
//  }
//  delay(500);
  
  if (Serial.available())
    mySerial.write(Serial.read());
	// Do nothing here...
}
