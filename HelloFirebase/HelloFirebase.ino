#include <ESP8266WiFi.h>



//Config Connected Router
#define WiFi_SSID "MastreEWTC_2.4G"
#define WiFi_Password "12345abcde"


void setup() 
{
  Serial.begin(9600);
 
 // Connected Router
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi_SSID,WiFi_Password);
  Serial.print("Connecting");

  while(WiFi.status()!=WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    Serial.print("Sucess Connected : ");
    Serial.println(WiFi.localIP());



} // Setup

void loop() {
  // put your main code here, to run repeatedly:

}
