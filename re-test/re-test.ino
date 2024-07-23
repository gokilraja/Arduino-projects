#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x3F, 16, 2);
SoftwareSerial mySerial(10,11); // RX, TX
void setup()
{
  // initialize the LCD
//  lcd.begin();
//
//  // Turn on the blacklight and print a message.
//  lcd.backlight();
//  lcd.setCursor(0,0);
//  lcd.print("NO Accident HERE");
//  lcd.setCursor(0,1);
//  lcd.print("Drive to safe!");
//  delay(1000);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
//  while (!Serial) {
//    ; // wait for serial port to connect. Needed for Leonardo only
//  }
//Serial.println("welcome!");
  mySerial.begin(9600);
}
void loop()
{
//  char al=0;
//  int a=1;
//  while(a>=19){
  
  if (mySerial.available()){
    String a1=mySerial.readString();
    Serial.print(a1);
//    a=a+1;
     digitalWrite(8,HIGH);
     delay(1000);
     digitalWrite(8,LOW);
     delay(1000);
     digitalWrite(8,HIGH);
     delay(1000);
     digitalWrite(8,LOW);
     delay(1000);
     digitalWrite(8,HIGH);
     delay(1000);
     digitalWrite(8,LOW);
  }
  if (Serial.available())
    mySerial.write(Serial.read());
  // Do nothing here...
}
