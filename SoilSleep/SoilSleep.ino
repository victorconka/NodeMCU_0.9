#include <ESP8266WiFi.h>
#define SLEEP_DELAY_IN_SECONDS 3
float i = 0;
float i2 = 0;
double value;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(D2,OUTPUT);
}

void loop() {
  delay(500);
  Serial.println();
  Serial.println("I woke up");
  digitalWrite(D2,HIGH);
  delay(2000);
  
  i = analogRead(A0);
  i2 = map(i,955,260,0,1024);
  value = map(i2,0,1024,0,100);
  Serial.print("lectura - ");
  Serial.println(i);
  Serial.print("porcentaje - ");
  if(value < 0){
    value = 0.0;
  }else if(value > 100.0){
    value = 100.0;
    }
  Serial.print(value);
  Serial.println("%"); 
  Serial.println("I am goin to sleep");
  digitalWrite(D2,LOW);
  sleep();
}
void sleep(){
  ESP.deepSleep((SLEEP_DELAY_IN_SECONDS * 1000000), WAKE_RF_DEFAULT);
  
}
