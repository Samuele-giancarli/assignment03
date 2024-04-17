#include "ButtonTask.h"
#include "Arduino.h"

unsigned long startDelay = 0;

ButtonTask::ButtonTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void ButtonTask::tick()
{
    if (digitalRead(BUTTONPORT) == HIGH && (millis()-startDelay)>=1000)
    {

        Serial.write("Button pressed, changing state\n");
        if(stateHandler->isStateManual()) {
            stateHandler->setStateAutomatic();
        } else {
            stateHandler->setStateManual();
        }
        startDelay=millis();
        
    }
    Serial.write("é passato: ");
    Serial.println(startDelay);
}