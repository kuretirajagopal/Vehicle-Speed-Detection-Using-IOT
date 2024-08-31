#include<SoftwareSerial.h>
//9 = Rx & 10 = Tx
SoftwareSerial actuation(9 , 10);
int buzzer = 11;
void setup() {
pinMode(buzzer , OUTPUT);
Serial.begin(9600);

actuation.begin(9600);
delay(1000);
}
void loop() {
int result ;
if(actuation.available()>0){ 
  result = actuation.read();
Serial.println(result);
if(result>=50){
tone(buzzer, 40);

delay(1000);
}
noTone(buzzer);
}
}
