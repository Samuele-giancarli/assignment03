#include <WiFi.h>
#include <PubSubClient.h>
#define MSG_BUFFER_SIZE  50

/* wifi network info */
const char* ssid = "OPPO A9 2020";
const char* password = "vv6miwa8";

/* MQTT server address */
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;

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







hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool timerFinished = false;

void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    //timerFinished = true;
    if (timerAlarmRead(timer) == 100) {
        timer100Ended = true;
    } else if (timerAlarmRead(timer) == 1000) {
        timer1000Ended = true;
    } else if (timerAlarmRead(timer) == 5000) {
        timer5000Ended = true;
    }
    portEXIT_CRITICAL_ISR(&timerMux);

}

void setupTimer(){
  Serial.begin(115200);
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000, false);
  timerAlarmEnable(timer);
}






void setup_wifi() {

  //delay(100); //-----------------------
  timer100Ended = false;
  timerRestart(timer);
  while(!timer100Ended){
  }

  Serial.println(String("Connecting to ") + ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    //delay(500); //-----------------------
    timer500Ended = false;
    timerRestart(timer);
    while(!timer500Ended){
    }
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

/* MQTT subscribing callback -> viene chiamato ogni volta che viene postato un messaggio sul topic*/
void callbackSystemState(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
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
      //delay(5000);//-----------------------
      timer5000Ended = false;
      timerRestart(timer);
      while(!timer5000Ended){
      }
    }
  }
}

long calDist(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);//-----------------------
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
    Serial.print("Water level: ");
    Serial.println(calDist());
    //delay(1000);//-----------------------
    timer1000Ended = false;
    timerRestart(timer);
    while(!timer1000Ended){
    }

    snprintf (msg, MSG_BUFFER_SIZE, "%ld", calDist());
    delay(1000);

    /* publishing the msg */
    client.publish(waterLevelTopic, msg); 
    //delay(1000);//-----------------------
    timer1000Ended = false;
    timerRestart(timer);
    while(!timer1000Ended){
    }
}
}

void setup() {
  Serial.begin(9600);
  while(!Serial) {

  }

  setup_wifi();
  randomSeed(micros());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callbackSystemState);
  client.subscribe(systemStateTopic);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}


void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  sendWaterLevel();
}