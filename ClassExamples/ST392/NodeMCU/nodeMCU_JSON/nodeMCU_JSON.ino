#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "JSON.h"

const char* ssid     = "Electronics";
const char* password = "12345678";
void  jsonPOST(String);
// JSON String - {"username":"demo","name":"test101","sample1":"9","sample2":"99","sample5":"-1"}

String username="ST392";
String Device_No="sensor1" ; 
int CELSIUS=89, HUM =49;

 //form the JSON string with the available sensor data
String getJSON(){
  String data ;
   data += "{\"username\":\"" + String(username)  + "\",\"name\":\"";
   data += String(Device_No);
   data += "\",\"sample1\":\"";
   data += String( CELSIUS); //(unsigned char)
   data += "\",\"sample2\":\"";
   data += String(HUM); 
   data += "\",\"sample5\":\"";
   int nosample=-1;
   data += String(nosample); 
   data += "\"}";
   return data;
}
void setup() {
 Serial.begin(115200);
  delay(10);
 // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}
void loop() {
    String content =  getJSON() ;
    jsonPOST( content);
  delay(5000) ;
}