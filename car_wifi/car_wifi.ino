

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include<Wire.h>
#include "mainPage.h"

const int Load1=16;
const int Load2=14;
const int Load3=12;
const int Load4=13;

/* Set these to your desired credentials. */
const char *ssid = "";
const char *password = "";

ESP8266WebServer server(80);
String L1Status,L2Status,L3Status,L4Status;
//=======================================================================
//                    handles main page 192.168.4.1
//=======================================================================
/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
  String s = MAIN_page;    
  s.replace("@@L1@@", L1Status);
  s.replace("@@L2@@", L2Status);
  s.replace("@@L3@@", L3Status);
  s.replace("@@L4@@", L4Status);
 
  server.send(200, "text/html", s);    
}

//=======================================================================
//                    Handle Set Date/Time Settings
//=======================================================================
void handleForm() {
	Wire.begin(4, 5);
  Serial.begin(115200);
  
  Wire.beginTransmission(0x08);
  Wire.write(0x23);
  byte busStatus = Wire.endTransmission();
  Serial.println(busStatus);

  Wire.requestFrom(0x08, 1);
  byte x = Wire.read();
  
  String t_state = server.arg("submit");
  
  
  
//Change Load-1 State as per request
  if(t_state=="ON1")
  {
    L1Status="ON";    
    digitalWrite(Load1, HIGH);       //Load1 Turned on
  }
  
  if(t_state=="OFF1")
  {
    L1Status="OFF";    
    digitalWrite(Load1, LOW);      //Load1 Turned off  
  }
//Change Load-2 State as per request
  if(t_state=="ON2")
  {
    L2Status="ON";    
    digitalWrite(Load2, HIGH);       //Load1 Turned on
  }
  
  if(t_state=="OFF2")
  {
    L2Status="OFF";    
    digitalWrite(Load2, LOW);      //Load1 Turned off  
  }
//Change Load-3 State as per request
  if(t_state=="ON3")
  {
    L3Status="ON";    
    digitalWrite(Load3, HIGH);       //Load1 Turned on
  }
  
  if(t_state=="OFF3")
  {
    L3Status="OFF";    
    digitalWrite(Load3, LOW);      //Load1 Turned off  
  }
//Change Load-4 State as per request
  if(t_state=="ON4")
  {
    L4Status="ON";    
    digitalWrite(Load4, HIGH);       //Load1 Turned on
  }
  
  if(t_state=="OFF4")
  {
    L4Status="OFF";    
    digitalWrite(Load4, LOW);      //Load1 Turned off  
  }

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");  //This Line Keeps It on Same Page
   
  delay(500);
}
//=======================================================================
//                    Power on setup
//=======================================================================

void setup() {
  delay(1000);
 
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  server.on("/", handleRoot);
  server.on("/form", handleForm);
 
  server.begin();
  pinMode(Load1, OUTPUT);
  pinMode(Load2, OUTPUT);
  pinMode(Load3, OUTPUT);
  pinMode(Load4, OUTPUT);  
}

//=======================================================================
//                    Main Program Loop
//=======================================================================
void loop() {
  server.handleClient();
}
//=======================================================================
