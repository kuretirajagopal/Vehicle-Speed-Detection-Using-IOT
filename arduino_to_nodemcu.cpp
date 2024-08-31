
#include <SoftwareSerial.h>
//Initialise Arduino to NodeMCU (5=Rx & 6=Tx)
SoftwareSerial s(5, 6);
int timer1;
int timer2;
float Time;
int flag1 = 0;
int flag2 = 0;
float distance = 5.0;
float curr_speed;
int ir_s1 = 2;
int ir_s2 = 3;
void setup() {
pinMode(ir_s1 , INPUT);
pinMode(ir_s2 , INPUT);
Serial.begin(9600);
s.begin(9600);
delay(1000);
Serial.println("Program started");
}
void loop() {

  if(digitalRead (ir_s1) == LOW && flag1==0)
  {
    timer1 = millis();flag1=1;
  }
  if(digitalRead (ir_s2) == LOW && flag2==0)
  {
    timer2 = millis();flag2=1;
  }
  if (flag1==1 && flag2==1){

    if(timer1 > timer2){
      Time = timer1 - timer2;
    }
    else if(timer2 > timer1){
      Time = timer2 - timer1;
    }
    Time=Time/1000;
    curr_speed=(distance/Time);
    curr_speed=curr_speed*3600;
    curr_speed=curr_speed/1000;
  }
  if(curr_speed==0){
    if(flag1==0 && flag2==0)
    {
      Serial.println("No car detected");
    }
    else{
      Serial.println("waiting... ");
    }
  }
  else{
    Serial.println("curr_speed:");
    Serial.println(curr_speed,1);
    Serial.println("Km/Hr ");
    s.write(curr_speed);
    if(curr_speed > 50){
      Serial.println(" Over speeding ");
    }
    else{
      Serial.println(" Normal speed ");
    }
    delay(3000);

    curr_speed = 0;
    flag1 = 0;
    flag2 = 0;
    }
  delay(100);
}
