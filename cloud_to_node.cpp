#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char apiKey[] = "TH14ZPKU3A7770UM";
const char readApiKey[] = "SYW5P4490W7RPE4P";
long channelID = 2281321;
const int fieldNumber = 2;
const char *ssid = "POCO X2";
const char *pass = "09876543";
const char* server = "api.thingspeak.com";
WiFiClient client;
//D3 = Rx & D2 = Tx
SoftwareSerial actuation(D3 , D2);
void setup() {
Serial.begin(9600);

actuation.begin(9600);
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
delay(1000);
}
void loop() {
long speedFromCloud=ThingSpeak.readLongField(channelID , fieldNumber , readApiKey);
int statusCode = ThingSpeak.getLastReadStatus();
if(statusCode == 200)
{
Serial.println(speedFromCloud);
Serial.println("this is coming from the cloud");
Serial.println(speedFromCloud);
actuation.write(speedFromCloud);
delay(1000);
}
else Serial.println("some error occurred while reading the channel");
}
