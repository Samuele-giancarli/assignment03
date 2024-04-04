#include "serial.h"
#include "Arduino.h"

SerialImpl::SerialImpl(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
} 

bool read() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readStringUntil('\n');
  if (incomingByte != -1) {
    char* angleString = strtok(incomingByte.c_str(), ","); // Split the string by comma
    char* modeString = strtok(NULL, ","); // Get the next token

    if (angleString != NULL && modeString != NULL) {
      angle = atoi(angleString); // Convert angle string to integer
      mode = (strcmp(modeString, "ON") == 0);
    return true;
  }
}

int getAngle() {
  return angle;
}

bool getMode() {
  return mode;
}

void sendSerial() {
  Serial.println(angle + "," + mode ? "ON" : "OFF");
}


  
