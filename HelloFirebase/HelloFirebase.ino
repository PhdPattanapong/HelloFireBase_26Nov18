
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>


//Config Connected Router
#define WiFi_SSID "MastreEWTC_2.4G"
#define WiFi_Password "12345abcde"

// Config Connected Data Base
#define Firebase_Host "greenhouse-3073d.firebaseio.com"
#define Firebase_Auth "Wogx5BtFbmZ02JGlC8y83BGUlBjX0A8YORUNAOuX"

//Config Swift LED
#define SwitchtLed D1
#define SwitchtLed2 D2

// Explicit
int countInt = 0;
int SignalFirebase=0;
int SignalFirebase2=0;
void setup() 
{
  Serial.begin(9600);
  
 // Connected Router
 
  WiFi.mode(WIFI_STA);
  WiFi.begin(WiFi_SSID,WiFi_Password);
  Serial.print("Connecting");

  //Config Output
  pinMode(SwitchtLed,OUTPUT);
  pinMode(SwitchtLed2,OUTPUT);

  while(WiFi.status()!=WL_CONNECTED){
      Serial.print(".");
      delay(500);
    }
    Serial.println();
    Serial.print("Sucess Connected : ");
    Serial.println(WiFi.localIP());
   
//    Start Connected Firebase
    Firebase.begin(Firebase_Host, Firebase_Auth);


} // Setup

void loop() {

  // Increase countInt
  countInt++;

  Serial.print(" CountInt ==> " );
  Serial.println(countInt);

  // Post Value To FireBase

  Firebase.setInt("FromNode/numberAnInt", countInt);


 // Read Value From FireBase

  SignalFirebase = Firebase.getInt("FromMobile/signal");
  SignalFirebase2 = Firebase.getInt("FromAndriod/signal");
    Serial.print(" SignalFibase ==> " );
    Serial.println(SignalFirebase);

    
   
  if(SignalFirebase==1){
      digitalWrite(SwitchtLed,HIGH);
    } else{
          digitalWrite(SwitchtLed,LOW);
        }

   if(SignalFirebase2==1){
      digitalWrite(SwitchtLed2,HIGH);
    }
    else{
          digitalWrite(SwitchtLed2,LOW);
        }
  
  delay(1000);

} // loop 











