/*
 * Second example, about tasks that can be run
 * thanks to FreeRTOS support.  
 *
 */

/*
  ESP:
  - tolgiere i delay e utilizzare gli interrupt
  ogni tot si deve svegliare e calcolare la distanza del sonar
  - funzione di callback da modificare per fargli modificare la frequenza concui ha l'interrupt
  - 
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



hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool timerFinished = false;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    timerFinished = true;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void setupTimer(){
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 100000, false);
  timerAlarmEnable(timer);
}



void wifiSetup() {
  //-------------------
  timerFinished = false;
  timerRestart(timer);
  while(!timerFinished){
  }
  //--------------------
  Serial.print("\nConnection to");
  Serial.print(ssid);

  //-------------------
  timerFinished = false;
  timerRestart(timer);
  while(!timerFinished){
  }
  //--------------------
  WiFi.begin(ssid,pass);

  while(WiFi.status() != WL_CONNECTED) {
  //-------------------
  timerFinished = false;
  timerRestart(timer);
  while(!timerFinished){
  }
  //--------------------
    Serial.print(".");
  }
  Serial.print("Connection succesful");
  //-------------------
  timerFinished = false;
  timerRestart(timer);
  while(!timerFinished){
  }
  //--------------------
}

void reconnect() {
  while(!client.connected()) {
    Serial.print("\nConnecting");
    if(client.connect("koikoikoi", brokerUser.c_str(), brokerPass.c_str())){
      Serial.print("\nConnected to");
      Serial.println(broker);
    } else {
      Serial.print("Trying connecting again");
      //-------------------
      timerFinished = false;
      timerRestart(timer);
      while(!timerFinished){
      }
      //--------------------
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
   //-------------------
    timerFinished = false;
    timerRestart(timer);
    while(!timerFinished){
    }
    //--------------------
  // Wait for a second
  //delay(1000);
}
