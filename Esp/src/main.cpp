/********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-hc-sr04-ultrasonic-arduino/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <Wire.h>
#include <ArduinoJson.h>


const int trigPin = 37;
const int echoPin = 36;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
float distanceInch;

const String ssid = "OPPO A9 2020";
const String pass = "vv6miwa8";
const String mqtt_serv = "10.201.107.95";

WiFiClient espClient;
PubSubClient client(espClient);

StaticJsonDocument<80> doc;
String output;

float distance = 0;
long lastMsg =  0;

void setup() {
  Serial.begin(460800); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

  delay(100);
  while(!Serial) {
  }

  Serial.print("");
  Serial.print("Connecting to:");
  Serial.print(ssid);
  WiFi.begin(ssid,pass);

  while(WiFi.status()!= WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  
  Serial.print("");
  Serial.print("Connected! IP:");
  Serial.print(WiFi.localIP());

  client.setServer(mqtt_serv, 1883);
}

void loop() {
  if(!client.connected()) {
    reconnect();
  }
  long now =  millis();
  if(now - lastMsg > 3000) {
    lastMsg =  now;
    distance = calDist();
    doc["d"] = distance;
    serializeJson(doc,output);
    Serial.println(output);
    //client.publish("/", output);
  }

}

int calDist(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);       
  digitalWrite(trigPin,  LOW);                                                     
  duration =  pulseIn(echoPin, HIGH);                            
  distance= duration*SOUND_SPEED/2;                  
  return distance;
}


void reconnect() {
  while(!client.connected()) {
    Serial.print("MQTT not connected... Trying to connect");
  }

   String clientId = "ESP32Client-";
  clientId += String(random(0xffff), HEX);

  if(client.connect(clientId.c_str())) {
    Serial.print("Connected");
  } else{
    Serial.print("Failed, response code");
    Serial.print(client.state());
  }
}
*********/

//hivemq.webclient.1715004587368
//402Ag3QBJXNca>.,ebd<

#include <WiFi.h>
#include <PubSubClient.h>
#define MSG_BUFFER_SIZE  50


/* wifi network info */

const char* ssid = "OPPO A9 2020";
const char* password = "vv6miwa8";

/* MQTT server address */
const char* mqtt_server = "broker.mqtt-dashboard.com";

/* MQTT topic */
const char* waterLevelTopic = "water-level-topic";
const char* systemStateTopic = "system-state-topic";

/* MQTT client management */

WiFiClient espClient;
PubSubClient client(espClient);


unsigned long lastMsgTime = 0;
char msg[MSG_BUFFER_SIZE];
int value = 0;

float distance = 0;
const int trigPin = 12;
const int echoPin = 13;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
const int waterTime = 6000;


void setup_wifi() {

  delay(100);

  Serial.println(String("Connecting to ") + ssid);

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

/* MQTT subscribing callback -> viene chiamato ogni volta che viene postato un messaggio sul topic*/
void callbackSystemState(char* topic, byte* payload, unsigned int length) {
  Serial.println("trapano");
  delay(1000);
  if(topic == systemStateTopic) {
    Serial.println(String("Message arrived on [") + topic + "] len: " + length );
    delay(1000);
  }
}

void reconnect() {
  
  // Loop until we're reconnected
  
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Create a random client ID
    String clientId = String("Water-client-")+String(random(0xffff), HEX);

    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      // client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe(systemStateTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

long calDist(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // measure duration of pulse from ECHO pin
  duration = pulseIn(echoPin, HIGH);
  // calculate the distance
  distance = 0.017 * duration;                
  return distance;
}

void sendWaterLevel() {
    unsigned long now = millis();
    if (now - lastMsgTime > waterTime) {
    lastMsgTime = now;
    Serial.println("banana");
  delay(1000);
    Serial.print("Water level: ");
    Serial.println(calDist());
    delay(1000);
    snprintf (msg, MSG_BUFFER_SIZE, "%ld", calDist());
delay(1000);

    /* publishing the msg */
    client.publish(waterLevelTopic, msg); 
    delay(1000);
}
}

void setup() {
  Serial.begin(9600);
  while(!Serial) {
  }

  setup_wifi();
  randomSeed(micros());
  client.setServer(mqtt_server, 1883);
  client.setCallback(callbackSystemState);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() {

  if (!client.connected()) {
    reconnect();
  }
  Serial.println("papera");
  delay(1000);
  client.loop();
  sendWaterLevel();
}