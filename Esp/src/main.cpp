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
String pass = "";
String brokerUser = "ginevra.bartolini@studio.unibo.it";
String brokerPass = "4Rc8mak_01";
String broker = "mqtt.dioty.co";

WiFiClient espClient;
PubSubClient client(espClient);

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

void reconnect() {
  while(!client.connected()) {
    Serial.print("\nConnecting");
    if(client.connect("koikoikoi", brokerUser.c_str(), brokerPass.c_str())){
      Serial.print("\nConnected to");
      Serial.println(broker);
    } else {
      Serial.print("Trying connecting again");
      delay(10000);
    }
  }
}

void setup() {
  // Start the serial communication with the ESP device
  Serial.begin(460800);
  wifiSetup();
  client.setServer(broker.c_str(), 1883);
  Serial.println("aaaaaaa, World!");
}

void loop() {
  // Print a test message
  if(!client.connected()){
    reconnect();
  }
   Serial.print("\nScemo");
   delay(1000);
  // Wait for a second
  //delay(1000);
}
