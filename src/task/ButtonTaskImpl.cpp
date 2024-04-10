#include "ButtonTask.h"
#include "Arduino.h"

ButtonTask::ButtonTask(ChangeStateTask* stateHandler) {
    this->stateHandler = stateHandler;
}

void ButtonTask::tick()
{
    if (digitalRead(BUTTONPORT) == HIGH)
    {
        Serial.write("Button pressed, changing state\n");
        if(stateHandler->isStateManual()) {
            stateHandler->setStateAutomatic();
        } else {
            stateHandler->setStateManual();
        }
        
    }
}