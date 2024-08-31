
#include <SoftwareSerial.h>

#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char* apiKey = "TH14ZPKU3A7770UM";
const char readApiKey[] = "SYW5P4490W7RPE4P";
//D6 = Rx & D5 = Tx
int count=1;
SoftwareSerial s(D6 , D5);
long channelID = 2281321;
const int fieldNumber = 2;
const char *ssid = "POCO X2";
const char *pass = "09876543";
const char* host = "api.thingspeak.com";
WiFiClient client;
void setup() {
Serial.begin(9600);
s.begin(9600);
WiFi.begin(ssid, pass); 
while(WiFi.status() != WL_CONNECTED)
{
delay(200);
Serial.print("still waiting to connect to internet");
}
Serial.println();
Serial.println("NodeMCU is connected!");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);
}
void loop() {
if(s.available()>0){
  int curr_speed=s.read();
  int x = ThingSpeak.writeField(channelID, 2, curr_speed, apiKey);
  if(x == 200 ){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}
delay(2000);
}

