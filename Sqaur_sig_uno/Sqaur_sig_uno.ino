// #include<TimerOne.h>
// unsigned long t=1000,f,k=512;
void setup() {
  Serial.begin(9600);
//  pinMode(A1,INPUT);
  pinMode(9,OUTPUT);
  // Timer1.initialize();
}

void loop() {
//  int va=analogRead(A1);
//  long f=map(va,0,1023,1,10);
  // Timer1.pwm(9,1000000/f);
//  for(int i=5;i<=10;i++){
    tone(9,5,128);
//    Serial.println(i);
//    delay(2000);  
//  }
  
//  tone(9,100,128);
  
}
