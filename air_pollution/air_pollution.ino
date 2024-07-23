#include <Wire.h> 
#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Create a SoftwareSerial object to communicate with the GPS module
SoftwareSerial sgps(9,10); // RX, TX
//SoftwareSerial mySerial(2,3); // RX, TX

//const int buttonPin = 2;     // the number of the pushbutton pin     // the number of the LED pin
//int buttonState = 0;
//int b1=1;
//int a=0;
// Create a TinyGPS object
TinyGPS gps;
//#define sensorPin 8

const int sensorPin = A0;    // pin that the sensor is attached to
//const int ledPin = 9;        // pin that the LED is attached to
int b=true; 
// variables:
int sensorValue = 0;         // the sensor value
int sensorMin = 1023;        // minimum sensor value
int sensorMax = 0;  

void setup() {
  Serial.begin(9600);
  sgps.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(sensorPin,INPUT);
//  mySerial.begin(9600);
//  pinMode(buttonPin, INPUT);
//  Serial.println("75%,11.314943,77.551872");
  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
   
}

void loop() {
//  buttonState = digitalRead(buttonPin);

    sensorValue = analogRead(sensorPin);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, sensorMin, sensorMax);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
//  Serial.println(sensorValue);
  
//  const int b=true;  
     // Read the analog value from sensor
//  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); // map the 10-bit data to 8-bit data
  if (sensorValue <= 500 && b==true){
//    analogWrite(ledPin, outputValue); // generate PWM signal
    digitalWrite(4,HIGH);
//    Serial.println(sensorValue);
    Serial.println("75% above,11.3139832,77.5510033");
    delay(1000);
    digitalWrite(4,LOW);
    b=false;
  }
  else{
    digitalWrite(4,LOW);
    
  }
//    digitalWrite(ledPin, LOW);
              // Return analog moisture value

char stlat[20];
char stlon[20];  
//  int But1=digitalRead(But);
  while (sgps.available())
    {
      
//      if(b1<=20){
//      Serial.println("Alert!!");
//      if(buttonState == HIGH){
//        Serial.println(b1);
      int c = sgps.read();
      if (gps.encode(c))
      {
        float slat,slon;
        gps.f_get_position(&slat, &slon);
//        char a1=slat;
//        char a2=slon;
//      Serial.print("A");
//        String lla=a1+a2;
        
        dtostrf(slat,9,6,stlat);
        dtostrf(slon,9,6,stlon);
        Serial.print(stlat);
        Serial.print(",");
        Serial.println(stlon);

        delay(100);
//       b1=b1+1;
      }

    }

      
}
