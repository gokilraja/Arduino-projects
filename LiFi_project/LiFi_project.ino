#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int redPin = 2;    // Red LED pin
const int greenPin = 3;  // Green LED pin
const int bluePin = 4;   // Blue LED pin
const int solarPin = 5; // Analog pin connected to the solar panel

void setup() {
    lcd.begin(); // Initialize LCD
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0,0);
  lcd.print("Waiting!..");
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(solarPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = digitalRead(solarPin);
  // Serial.println(lightLevel);
    // Serial.println(duration);
  int count=0;
  
  if (digitalRead(solarPin) ==0) {
    for(int i=0;digitalRead(solarPin)!=1;i++){
        // if(digitalRead(solarPin) !=1){
            delay(10);
            count++;
        // }
      }
    
  }
  if(count>0){
    if(count<70){
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("Break Failure");
      digitalWrite(redPin,HIGH);
      delay(1000);
      digitalWrite(redPin,LOW);
    }
    else if(count<120){
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("No Vision!");
        digitalWrite(greenPin,HIGH);
        delay(1000);
        digitalWrite(greenPin,LOW);
    }
    else if(count<250){
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("AMBULANCE emergency!");
        digitalWrite(bluePin,HIGH);
        delay(1000);
        digitalWrite(bluePin,LOW);
    }
  Serial.println(count);
  }
  // if(digitalRead(solarPin)==1){
  //       Serial.println(count);
  //       count=0;
  //   }
}