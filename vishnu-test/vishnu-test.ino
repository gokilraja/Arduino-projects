#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_TEMPLATE_ID "TMPL3_sKdjojh"
#define BLYNK_TEMPLATE_NAME "Smar parking2"
#define BLYNK_AUTH_TOKEN "v1mA7b46wLrulNQ4t8Se9-3ehxqq2zTf"

// Replace these with your Blynk authentication token and Wi-Fi credentials
//char auth[] = "YourAuthToken";
char ssid[] = "finder";
char pass[] = "123456789";

// Define the pins for the four IR sensors
#define irPin1 D1
#define irPin2 D2
#define irPin3 D3
#define irPin4 D4

void setup()
{
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);  // Initialize Blynk with your credentials
  pinMode(irPin1, INPUT);         // Set the IR sensor pins as inputs
  pinMode(irPin2, INPUT);
  pinMode(irPin3, INPUT);
  pinMode(irPin4, INPUT);
}

void loop()
{
  // Read the status of each IR sensor (HIGH or LOW)
  int status1 = digitalRead(irPin1);
  int status2 = digitalRead(irPin2);
  int status3 = digitalRead(irPin3);
  int status4 = digitalRead(irPin4);

  Blynk.run();  // Run the Blynk communication

  // Send the status of each parking space to corresponding virtual pins in the Blynk app
  Blynk.virtualWrite(V0, status1);
  Blynk.virtualWrite(V1, status2);
  Blynk.virtualWrite(V2, status3);
  Blynk.virtualWrite(V3, status4);
//  Blynk.virtualWrite(V0, 1);
//  Blynk.virtualWrite(V1, 0);
//  Blynk.virtualWrite(V2, 1);
//  Blynk.virtualWrite(V3, 1);
//  delay(1000);
//  Blynk.virtualWrite(V0, 1);
//  Blynk.virtualWrite(V1, 1);
//  Blynk.virtualWrite(V2, 0);
//  Blynk.virtualWrite(V3, 1);
//  delay(1000);
//  Blynk.virtualWrite(V0, 1);
//  Blynk.virtualWrite(V1, 1);
//  Blynk.virtualWrite(V2, 1);
//  Blynk.virtualWrite(V3, 0);
//  delay(1000);
//  Blynk.virtualWrite(V0, 0);
//  Blynk.virtualWrite(V1, 0);
//  Blynk.virtualWrite(V2, 0);
//  Blynk.virtualWrite(V3, 0);
  delay(1000);  // Update the status every second
}
