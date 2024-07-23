#include <Wire.h> 
#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Create a SoftwareSerial object to communicate with the GPS module
SoftwareSerial sgps(9,10); // RX, TX
//SoftwareSerial mySerial(2,3); // RX, TX

const int buttonPin = 2;     // the number of the pushbutton pin     // the number of the LED pin
int buttonState = 0;
int b1=1;
// Create a TinyGPS object
TinyGPS gps;
int b=true;
bool pr=false;


void setup() {
  Serial.begin(9600);
  sgps.begin(9600);
//  mySerial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
   
}

void loop() {
  bool sensorVal = digitalRead(2);
  //print out the value of the pushbutton
//  Serial.println(sensorVal);
  if (sensorVal == pr) {
    digitalWrite(13, HIGH);
    Serial.println("11.314038, 77.551019");
    while(digitalRead(2) == pr){
     
    }
    delay(500);
//    
  } 
  else {
    digitalWrite(13, LOW);
  }
  
  char stlat[20];
  char stlon[20];  
//  int But1=digitalRead(But);
  while (sgps.available())
    {
      
      if(b1<=20){
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
//      Serial.print(",");
//        mySerial.write(stlat[9]);
        delay(100);
       b1=b1+1;
      }
//        mySerial.write(stlon[9]);
//         Transmit latitude and longitude to the other board using the transceiver module
//        transmitData(slat, slon);
     //////
    }
//    else{
//      Serial.println(buttonState);
////      break;
//    }
      }
  
//  switch(But1){
//  case '1':
//    Serial.print(But1);
//    Serial.println("NO safe NOW");
//      delay(3000);
//      break;
//  
//  case 0:
//    Serial.print(But1);
//    Serial.println("You Are safe NOW");
//    delay(1000);
//    break;
//  }
//}
////void transmitData(double latitude, double longitude) {
//  // TODO: Configure and send the latitude and longitude values via the transceiver module to the other board
//  
}
//Make sure to connect the TX pin of the GPS module to the RX pin of the GPS Arduino board, and the TX pin of the transceiver module to the RX pin of the other Arduino board.
