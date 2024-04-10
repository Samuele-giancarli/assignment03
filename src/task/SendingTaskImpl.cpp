#include "SendingTask.h"
#include "Arduino.h"
#include "Config.h"

SendingTask::SendingTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void SendingTask::tick() {
    if(stateHandler->isStateAutomatic()) {
        int sensorValue = analogRead(POTPORT);
        stateHandler->setAngle(sensorValue);
        Serial.write("PAPERELLA GAY");
        Serial.write(stateHandler->getAngle());
        Serial.write(", ");
        Serial.write(stateHandler->isStateManual() ? MANUAL : AUTOMATIC);
    }
}


  
