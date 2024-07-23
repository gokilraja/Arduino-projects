#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x27, 16, 2);

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

#define buzz 7
#define led 6
// #define e 5
int lan=0;
// #define t/amil 4
const int buttonPin = 5;
const int buttonPin1 = 4;
void setup()
{
  pinMode(buzz,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin1, INPUT_PULLUP);
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);
  mlx.begin(); // Initialize MLX90614
  lcd.begin(); // Initialize LCD
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0,0);
  lcd.print("Select lang!");
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  myDFPlayer.volume(30);
}
void loop()
{
  char on=Serial.read();
  
  if(digitalRead(buttonPin)==0){
      lan=0;
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("English!");
  }
  else if(digitalRead(buttonPin1)==0){
      lan=1;
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Tamil!");
  }
  // myDFPlayer.playLargeFolder(1, 94);
  // delay(5000);
  if(on=='p'){
    digitalWrite(led, HIGH);
    int tempC = mlx.readObjectTempC(); 
    int tra=(tempC * 1.8 + 32);
    Serial.println(tempC);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.setCursor(0, 1); // Set cursor to second line
    lcd.print(tra);
    lcd.print(" F");
    delay(1000);
    Serial.println(tra);
    if(tra<=110){
      if(lan==0){
        myDFPlayer.playLargeFolder(1, tra);
      } //play specific mp3 in SD:/02/004.mp3; Folder Name(1~10); File Name(1~1000)
      else if(lan==1){
        myDFPlayer.playLargeFolder(2, tra);
      }
      if(tra>=97){
        digitalWrite(buzz, HIGH);
        delay(500);
        digitalWrite(buzz, LOW);
        delay(500);
        digitalWrite(buzz, HIGH);
        delay(500);
        digitalWrite(buzz, LOW);
      } 
      delay(5000);
    }
    digitalWrite(led, LOW);
  }
}
