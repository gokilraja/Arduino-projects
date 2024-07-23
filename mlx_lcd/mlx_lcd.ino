#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal_I2C.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
LiquidCrystal_I2C lcd(0x3F, 16, 2);

void setup() {
  Serial.begin(9600);
  mlx.begin(); // Initialize MLX90614
  lcd.begin(); // Initialize LCD
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
}

void loop() {
  float tempC = mlx.readObjectTempC(); // Read object temperature in Celsius
  lcd.setCursor(0, 1); // Set cursor to second line
  lcd.print(tempC);
  // lcd.print("hellao");
  Serial.print(tempC);
  Serial.print(" C  ");
  int tra=(tempC * 1.8 + 32);
    Serial.print(tra);
    Serial.println(" F");
  delay(1000); // Update temperature every second
}