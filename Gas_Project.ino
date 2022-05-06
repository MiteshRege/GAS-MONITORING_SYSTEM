#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

//------- WI-FI details ----------//
char ssid[] = "Miteshsensor"; //SSID here
char pass[] = "12345678"; // Passowrd here
//--------------------------------//

//----------- Channel details ----------------//
long Channel_ID = 1717194; // Your Channel ID
const char * myWriteAPIKey = "6QXFNUOJXZSGLLJR"; //Your write API key
//-------------------------------------------//

//const int Field_Number_1 = 1;
////const int Field_Number_2 = 2;
//String value = "";
//int value_1 = 0, value_2 = 0;
//int x, y;

WiFiClient  client;
int led = D4;
int mqu = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("Miteshsensor", "12345678");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(mqu);
//  Serial.println(val);
//  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  Serial.println("Led is on");
//  delay(1000);                       // wait for a second
//  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  Serial.println("Led is Off");
//  delay(1000);                       // wait for a second




  
  Serial.println("Gas : " + (String) val);
  
  ThingSpeak.writeField(Channel_ID, 1, val, myWriteAPIKey);
//  ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
  delay(2000);
}
