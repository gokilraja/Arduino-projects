#include <LiquidCrystal_I2C.h> //For display

LiquidCrystal_I2C lcd(0x27, 16, 2);

int vib_sen=7; 
int bazar_pin=2;
int red=6;
int blue=4;


void setup() {
  Serial.begin(9600);
  pinMode(vib_sen,INPUT);
  pinMode(bazar_pin,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
   lcd.begin();
  lcd.backlight();

}

void loop() {
     int vib;
     vib=digitalRead(vib_sen); //read data in vibration sensor
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("vibration mode");
     if(vib==1){
        digitalWrite(bazar_pin,HIGH); //the vibration sensor data is high (vibrating)
        lcd.setCursor(0,1);
        lcd.print("vibrating!");
        Serial.println("vibrating!");
        digitalWrite(blue,LOW);
        for(int i=1;i<=20;i++){
          digitalWrite(red,HIGH); 
          delay(800);
          digitalWrite(red,LOW); 
          delay(800);
        }
        delay(500);
     }
     else{
        digitalWrite(bazar_pin,LOW); //the vibration sensor data is high (vibrating)
        digitalWrite(blue,HIGH);
        lcd.setCursor(0,1);
        lcd.print("No vibrating!");
        Serial.println(" NO vibrating!");
        delay(500);
     }

}
