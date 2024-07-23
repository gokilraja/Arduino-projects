int a=2;
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int dg1=9;
int dg2=10;
int dg3=11;
void setup() {
  // put your setup code here, to run once:
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(dg1,OUTPUT);
  pinMode(dg2,OUTPUT);
  pinMode(dg3,OUTPUT);


}

void loop() {
  for(int i=1;i<50;i++){
    ECE();
  }
  delay(1000);
  for(int i=1;i<50;i++){
    EIE();
  }
  // clr();
  // EIE();
  delay(1000);
}
void ECE(){
  E();
  digitalWrite(dg1,LOW);
  digitalWrite(dg2,HIGH);
  digitalWrite(dg3,HIGH);
  delay(5);
  C();
  digitalWrite(dg1,HIGH);
  digitalWrite(dg2,LOW);
  digitalWrite(dg3,HIGH);
  delay(5);
  E();
  digitalWrite(dg1,HIGH);
  digitalWrite(dg2,HIGH);
  digitalWrite(dg3,LOW);
  delay(5);
  clr();
  delay(5);
}
void EIE(){
  E();
  digitalWrite(dg1,LOW);
  digitalWrite(dg2,HIGH);
  digitalWrite(dg3,HIGH);
  delay(5);
  I();
  digitalWrite(dg1,HIGH);
  digitalWrite(dg2,LOW);
  digitalWrite(dg3,HIGH);
  delay(5);
  E();
  digitalWrite(dg1,HIGH);
  digitalWrite(dg2,HIGH);
  digitalWrite(dg3,LOW);
  delay(5);
  clr();
  delay(5);
}
void E(){
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void C(){
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
void I(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
}
void clr(){
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}