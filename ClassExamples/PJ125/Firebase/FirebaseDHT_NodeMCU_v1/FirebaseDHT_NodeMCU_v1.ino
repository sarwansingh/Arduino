// This program connects DHT sensor on pin 14 and push data to firebase
// the data from firebase can be displayed on Android app

#include <FirebaseArduino.h>
#include "DHT.h"

#include  <ESP8266WiFi.h>

// Set these to run example.
#define FIREBASE_HOST "yyyyyyyyyyyy.firebaseio.com"
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
#define WIFI_SSID   "ssssss"
#define WIFI_PASSWORD "pppppp"

#define DHTPIN 14    // Data Pin of DHT 11 , for NodeMCU D5 GPIO no. is 14

#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  dht.begin();
  Serial.println ("");
  Serial.println ("WiFi Connected!");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
 
void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Reading temperature as Celsius (the default)

  Firebase.setFloat ("Temp", t);
  Firebase.setFloat ("Humidity", h);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  Serial.print ("Temp :");
  Serial.println(t);
  Serial.print ("Humidity :");
  Serial.println(h);
   
  delay(1000);
}
 
