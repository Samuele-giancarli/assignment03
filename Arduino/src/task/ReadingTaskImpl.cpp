#include "ReadingTask.h"
#include "Arduino.h"
#include "Config.h"

String incomingString;
double angle = 750;
// enum {MAN, AUTO} mode;

ReadingTask::ReadingTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void ReadingTask::tick() {
   Serial.print("Entro in reading: ");
    read();
    // if(mode==MAN && !stateHandler->isStateManual()) {
    //     stateHandler->setStateManual();
    // }
    stateHandler->setAngle(angle);
    Serial.print("Esco da reading: ");
}

char incomingMessage[50]; // Buffer to hold incoming message
int index = 0;

void ReadingTask::read() {

  if(Serial.available() < 0) {
    Serial.print("No data available");
  }
    //Checks for available data on the serial
  while (Serial.available() > 0 && index < 50) { // Read until newline or buffer full
    char incomingByte = Serial.read();
    if (incomingByte != '\n') { // If the byte is not a newline character
      incomingMessage[index] = incomingByte; // Store it in the buffer
      index++;
    } else {
      incomingMessage[index] = '\0'; // Null-terminate the string
      Serial.print("Message received: ");
      Serial.println(incomingMessage);
      index = 0; // Reset index for next message
    }
  }
     //incomingString = Serial.readString();


  // if (incomingString.length() > 0) {

  //   Serial.write("Sono in reading 2");

  //     int commaPos = incomingString.indexOf(',');
  //     int newlinePos = incomingString.indexOf('\n');

  //     // Extract angle and mode strings
  //     String angleString = incomingString.substring(0, commaPos);
  //     String modeString = incomingString.substring(commaPos + 1, newlinePos);

  //     // Convert angle string to integer
  //     angle = angleString.toInt();

  //     // Compare mode string to determine mode
  //     mode = (modeString == "MANUAL") ? MAN : AUTO;
  //     Serial.write("Sono in reading 3");
  //     Serial.write(mode);
  // }

    
}
  
