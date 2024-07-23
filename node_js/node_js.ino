#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  lcd.begin();
  lcd.backlight();
  lcd.print("Waiting For msg...");
  // Initialize the serial port at a speed of 9600 baud
  Serial.begin(9600);
}

void loop()
{
  // If characters arrived over the serial port...
  if (Serial.available() > 0) {
    // Wait a bit for the entire message to arrive
    delay(100);
    // Clear the screen
    lcd.clear();     
     char mod=Serial.read(); 
   if(mod == '3'){
      digitalWrite(3,HIGH);
     lcd.print("LED1 ON!");
   }
else if(mod == '2'){
      digitalWrite(3,LOW);
      lcd.print("LED1 OFF!");
}
else if(mod == '5'){
      digitalWrite(4,HIGH);
      lcd.print("LED2 ON!");
}
//    case '4':
else if(mod == '4'){
      digitalWrite(4,LOW);
      lcd.print("LED2 OFF!");

}
  }
}
