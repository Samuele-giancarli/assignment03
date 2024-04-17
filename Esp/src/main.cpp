/*
 * Second example, about tasks that can be run
 * thanks to FreeRTOS support.  
 *
 */
 
#include <HardwareSerial.h>
#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>

String ssid = "OPPO A9 2020";
String pass = "vv6miwa8";

void wifiSetup() {
  delay(10000);
  Serial.print("\nConnection to");
  Serial.print(ssid);

  delay(10000);

  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.print("Connection succesful");
  delay(10000);
}

void setup() {
  // Start the serial communication with the ESP device
  Serial.begin(460800);
  wifiSetup();
  Serial.println("aaaaaaa, World!");
}

void loop() {
  // Print a test message
   Serial.print("\nScemo");
   delay(1000);
  // Wait for a second
  //delay(1000);
}