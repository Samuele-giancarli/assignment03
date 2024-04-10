#include "ReadingTask.h"
#include "Arduino.h"
#include "Config.h"

String incomingByte;
int angle = 750;
enum {MAN, AUTO} mode;

ReadingTask::ReadingTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void ReadingTask::tick() {
    delay(2000);
    read();
    if(mode==MAN && !stateHandler->isStateManual()) {
        stateHandler->setStateManual();
    }
    stateHandler->setAngle(angle);
}

void ReadingTask::read() {
    //Checks for available data on the serial
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readStringUntil('\n');
  if (incomingByte.length() > 0) {

    char incomingByteArray[incomingByte.length() + 1]; // +1 for the null terminator
    strcpy(incomingByteArray, incomingByte.c_str());

    char* angleString = strtok(incomingByteArray, ","); // Now using a modifiable array
    char* modeString = strtok(NULL, "\n"); // Get the next token

    if (angleString != NULL && modeString != NULL) {
      angle = atoi(angleString); // Convert angle string to integer
      mode = (strcmp(modeString, MANUAL) == 0) ? MAN : AUTO;
    }
  }
  }
}
  
