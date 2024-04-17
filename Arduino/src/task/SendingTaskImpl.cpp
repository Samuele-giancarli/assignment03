#include "SendingTask.h"
#include "Arduino.h"
#include "Config.h"

SendingTask::SendingTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void SendingTask::tick() {
    if(stateHandler->isStateAutomatic()) {
        int sensorValue = analogRead(POTPORT);
        int servoAngle = map(sensorValue, 0, 1023, MINANGLE, MAXANGLE);
        stateHandler->setAngle(servoAngle);
        Serial.write("PAPERELLA GAY");
    }   
        
        while (Serial.read() >= 0); // do nothing
        
        String message = String(stateHandler->getAngle()) + ", " + (stateHandler->isStateManual() ? "MANUAL" : "AUTOMATIC");
        Serial.println(message);

        //delay(1000);
}


  
