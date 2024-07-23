 #include <VirtualWire.h>  
 const int ledPin = 9;  
 char *data;  
 void setup()   
 {  
  pinMode(ledPin,OUTPUT);  
  vw_set_ptt_inverted(true);  
  vw_set_tx_pin(12);  
  vw_setup(4000);
  Serial.begin(9600);  
 }  
 void loop()  
 {  
  data="0";  
  vw_send((uint8_t *)data, strlen(data));  
  vw_wait_tx();  
  digitalWrite(ledPin,HIGH);  
  delay(500);  
  data="1";  
  vw_send((uint8_t *)data, strlen(data));  
  vw_wait_tx();  
  digitalWrite(ledPin,LOW);  
  delay(500);  
 }  
