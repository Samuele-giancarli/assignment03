#include "serial.h"
#include "Arduino.h"

SerialImpl::SerialImpl(){
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
} 

bool SerialImpl::read() {
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readStringUntil('\n');
  if (incomingByte.length() > 0) {

    char incomingByteArray[incomingByte.length() + 1]; // +1 for the null terminator
    strcpy(incomingByteArray, incomingByte.c_str());

    char* angleString = strtok(incomingByteArray, ","); // Now using a modifiable array
    char* modeString = strtok(NULL, ","); // Get the next token

    if (angleString != NULL && modeString != NULL) {
      angle = atoi(angleString); // Convert angle string to integer
      mode = (strcmp(modeString, "ON") == 0);
    return true;
    }
  }
  }
}

int SerialImpl::getAngle() {
  return angle;
}

bool SerialImpl::getMode() {
  return mode;
}

void SerialImpl::sendSerial() {
  Serial.println(angle + "," + mode ? "ON" : "OFF");
}


  
